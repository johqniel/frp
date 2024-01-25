#include <random>

// In this file we define all the random number generators that we use in the model

// generates a random float in [0, upperBound]
float gen_random_float(float upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Use uniform distribution for [0, upperBound]
    std::uniform_real_distribution<float> distribution(0.0f, upperBound);

    // Generate a random float
    return distribution(gen);
}

float gen_random_normal(float mean, float sigma) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> distribution(mean, sigma);

    return distribution(gen);
};