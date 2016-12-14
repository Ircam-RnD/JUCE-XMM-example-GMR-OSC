# Getting started with Gaussian Mixture Regression in JUCE

#### simple JUCE example of an XMM-based OSC app

This example implements a wekinator-style application without GUI.  
It wraps several classes of the [XMM library](http://github.com/Ircam-RnD/xmm) together
and provides a simple and intuitive higher-level interface for gaussian mixture regression.  
It contains an example Max patch for testing the regression with a simple synthesizer.

#### installation

This repository contains a submodule, so you will need to use the `--recursive` option :  
`git clone --recursive https://github.com/Ircam-RnD/JUCE-XMM-example-GMR-OSC.git`
or `git submodule init` and `git submodule update` after doing a regular clone.  
In order for the project to compile, you should clone this repository into any
subfolder of the main juce folder. Otherwise you will have to update your juce modules
path from the projucer and regenerate the project.

#### license

See [XMM](https://github.com/Ircam-RnD/xmm)'s license

#### credits

This example is developed by the [ISMM](http://ismm.ircam.fr/) team at IRCAM,
within the context of the [RAPID-MIX](http://rapidmix.goldsmithsdigital.com/)
project, funded by the European Union’s Horizon 2020 research and innovation programme.  
Original XMM code authored by Jules Françoise.  
See [github.com/Ircam-RnD/xmm](https://github.com/Ircam-RnD/xmm) for detailed XMM credits.
