// main.cpp
// This file serves as the entry point for running the Convolutional Neural Network (CNN) application.


#include <iostream>
#include <vector>
#include <string>
#include "cnn.h"
#include "mnist_loader.h"

/**
 * Config: Structure to hold configurable parameters for the program.
 * - data_path: Path to the MNIST dataset.
 * - epochs: Number of training iterations (default: 5).
 * - batch_size: Number of samples per training batch (default: 1000).
 * - learning_rate: Step size for gradient descent (default: 0.01).
 */
struct Config {
  std::string data_path;
  int epochs = 5;
  int batch_size = 1000;
  float learning_rate = 0.01f;
};

/**
 * parse_arguments: Parses command-line arguments.
 * - Validates input and extracts dataset path, epochs, batch size, and learning rate.
 * - Throws runtime_error for invalid or insufficient arguments.
 */
Config parse_arguments(int argc, char* argv[]) {
  Config cfg;
  if (argc < 2) {
    throw std::runtime_error("Usage: " + std::string(argv[0]) + " <dataset_path> [epochs] [batch_size] [learning_rate]");
  }
  cfg.data_path = argv[1];
  if (argc > 2) cfg.epochs = std::stoi(argv[2]);
  if (argc > 3) cfg.batch_size = std::stoi(argv[3]);
  if (argc > 4) cfg.learning_rate = std::stof(argv[4]);
  return cfg;
}

/**
 * main: Entry point for the application.
 * Workflow:
 * 1. Parses program configuration using command-line arguments.
 * 2. Loads the MNIST dataset using MNISTLoader.
 *    - The training data is split into images and labels.
 * 3. Initializes the CNN with the following default architecture:
 *    - ConvLayer -> ReLULayer -> MaxPoolLayer -> FCLayer -> SigmoidLayer
 * 4. Trains the CNN on the training dataset for a specified number of epochs.
 *    - The training process includes forward propagation, backpropagation, and parameter updates.
 *    - Prints batch-wise loss and accuracy.
 * 5. Evaluates the CNN on the test dataset.
 *    - Computes accuracy and reports it to the console.
 * 6. Handles exceptions and outputs error messages if encountered.
 */

int main(int argc, char* argv[]) {
  try {
    Config cfg = parse_arguments(argc, argv);

    MNISTLoader mnist(cfg.data_path);
    auto train_data = mnist.loadTrainingData();
    auto test_data= mnist.loadTestData();

    auto cnn = create_default_cnn();
    cnn->train(std::get<0>(train_data), std::get<1>(train_data), cfg.epochs, cfg.batch_size, cfg.learning_rate);

    std::vector<int> correct, incorrect;
    float accuracy = cnn->evaluate(std::get<0>(test_data), std::get<1>(test_data), correct, incorrect);
    std::cout << "Test accuracy: " << accuracy * 100 << "%\n";

  }

  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}