# Convolutional Neural Network (CNN) for MNIST Image Recognition

This repository contains a C++ implementation of a minimal Convolutional Neural Network (CNN) designed for image recognition using the MNIST handwritten digits dataset. The purpose of the code is to demonstrates the core concepts of CNNs, including convolutional layers, pooling layers, fully connected layers, and activation functions.

## Table of Contents

- [Overview](#overview)
- [Dataset](#dataset)
- [Architecture](#architecture)
- [Usage](#usage)
  - [Build Instructions](#build-instructions)
  - [Command-Line Arguments](#command-line-arguments)
- [Results](#results)

## Overview

This project implements a CNN from scratch in C++ to classify handwritten digits from the MNIST dataset. The MNIST dataset consists of 28x28 grayscale images of digits (0-9), making it a standard benchmark for image recognition tasks. The CNN architecture includes convolutional layers, max-pooling layers, fully connected layers, and activation functions like ReLU and Sigmoid.

Features:

This implementation is inspired by classic CNN architectures and modern C++ practices.

- **Modular Design**: The code is organized into separate classes for each layer type (convolutional, pooling, fully connected, etc.), making it easy to extend or modify.
- **Training and Evaluation**: Includes functions for training the network, evaluating its performance, and making predictions on new images.

## Dataset

The MNIST dataset used for training and testing is included in this repository in the `dataset` folder. It is also available at [http://yann.lecun.com/exdb/mnist/](http://yann.lecun.com/exdb/mnist/). It contains:

- 60,000 training images
- 10,000 test images

Each image is a 28x28 grayscale image of a handwritten digit (0-9). The dataset is loaded using the `MNISTLoader` class, which reads the binary files and normalizes the pixel values to the range [0, 1].

## Architecture

The CNN architecture implemented in this project contains the following layers:

1. **Input Layer**: Accepts 28x28 grayscale images.
2. **Convolutional Layer**: Applies a set of learnable filters to extract features.
3. **ReLU Activation**: Introduces non-linearity to the model.
4. **Max-Pooling Layer**: Reduces spatial dimensions while retaining important features.
5. **Fully Connected Layer**: Maps extracted features to the output classes (digits 0-9).
6. **Sigmoid Activation**: Produces probabilities for each class.

The default architecture is constructed as `ConvLayer -> ReLULayer -> MaxPoolLayer -> FCLayer -> SigmoidLayer` with

- `ConvLayer` (1 input channel, 16 output channels, 3x3 kernel, stride 1)
- `ReLULayer`
- `MaxPoolLayer` (2x2 kernel, stride 2)
- `FCLayer` (13x13x16 input, 10 output)
- `SigmoidLayer`

### Build Instructions

All .cpp source files are located in the `src` folder and all .h header files are locatd in `include` folder. The code has no external dependencies. Everything is written from scratch.

### Command-Line Arguments

- `--dataset_path` : location of the MNIST training and test dataset. 
- `--epochs`: Number of training epochs (default: 5)
- `--batch-size`: Batch size for training (default: 100)
- `--learning-rate`: Learning rate for optimization (default: 0.01)

Example:

```bash
./mnist_cnn /path/to/mnist/dataset --epochs 10 --batch-size 256 --learning-rate 0.001
```

## Results

The model achieves an accuracy of approximately ~98% on the MNIST test set. 
