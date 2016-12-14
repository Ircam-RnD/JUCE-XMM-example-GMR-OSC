//
//  GmrWrapper.h
//  JUCE-XMM-example-GMR-OSC
//
//  Created by Joseph Larralde on 13/12/16.
//
//

#ifndef GmrWrapper_h
#define GmrWrapper_h

// try other settings here, but these ones work well for interpolation
#define GAUSSIANS 1
#define REL_REG 0.0001
#define ABS_REG 0.0001

#include "xmm.h"

class GmrWrapper {
private:
  xmm::Phrase *phrase;
  xmm::TrainingSet *set;
  xmm::GMM *gmr;
  String label;
  bool recording;
  std::vector<int> freeList; // list of free indices in training set
  int dimensionIn;
  int dimensionOut;

public:
  GmrWrapper(int dimIn, int dimOut) {
    dimensionIn = dimIn;
    dimensionOut = dimOut;
    
    phrase = new xmm::Phrase(xmm::MemoryMode::OwnMemory,
                             xmm::Multimodality::Bimodal);
    phrase->dimension.set(dimIn + dimOut);
    phrase->dimension_input.set(dimIn);
    
    set = new xmm::TrainingSet(xmm::MemoryMode::OwnMemory,
                               xmm::Multimodality::Bimodal);
    set->dimension.set(dimIn + dimOut);
    set->dimension_input.set(dimIn);

    gmr = new xmm::GMM(true);
    //gmr->configuration.multithreading = xmm::MultithreadingMode::Background;
    gmr->configuration.multithreading = xmm::MultithreadingMode::Sequential;
    //gmr->configuration.multiClass_regression_estimator = xmm::MultiClassRegressionEstimator::Likeliest;
    gmr->configuration.multiClass_regression_estimator = xmm::MultiClassRegressionEstimator::Mixture;
    gmr->configuration.gaussians.set(GAUSSIANS);
    gmr->configuration.relative_regularization.set(REL_REG);
    gmr->configuration.absolute_regularization.set(ABS_REG);
    gmr->configuration.changed = true;
    
    label = "1"; // default dummy label (works best with mono-label regression)
    recording = false;
  }
  
  ~GmrWrapper() {
    delete phrase;
    delete set;
    delete gmr;
  }
  
  void record(bool on) {
    recording = on;
    if (on) {
      phrase->clear();
    }
  }
  
  void add() {
    int index;
    if (this->freeList.size() == 0) {
      index = this->set->size();
    } else {
      index = this->freeList.back();
      this->freeList.pop_back();
    }
    this->phrase->label.set(this->label.toStdString());
    this->set->addPhrase(index, *(this->phrase));
    
    //std::cout << "phrase size : " << this->phrase->size() << std::endl;
    //std::cout << "set size : " << this->set->size() << std::endl;
    
    this->gmr->train(this->set);
    this->gmr->reset();
  }
  
  void setLabel(String label) {
    this->label = label;
  }
  
  void clearLabel() {
    xmm::TrainingSet *s = this->set->getPhrasesOfClass(this->label.toStdString());
    for (auto const &phrase : *s) {
      this->freeList.push_back(phrase.first);
    }
    std::sort(this->freeList.begin(), this->freeList.end(), std::greater<int>());
    this->set->removePhrasesOfClass(this->label.toStdString());
  }
  
  void clear() {
    this->set->clear();
    this->freeList.clear();
  }
  
  std::vector<float> setInput(std::vector<float>& input) {
    std::vector<float>::iterator it = input.begin();
    std::vector<float> i = std::vector<float>(it, it + dimensionIn);
    std::vector<float> o = std::vector<float>(it + dimensionIn, it + dimensionIn + dimensionOut);

    if (recording) {
      this->phrase->record_input(i);
      this->phrase->record_output(o);
      std::vector<float> tmp;
      return tmp;
    }
    
    this->gmr->filter(i);
    xmm::Results<xmm::GMM>& res = this->gmr->results;
    return res.output_values;
  }
  
};

#endif /* GmrWrapper_h */
