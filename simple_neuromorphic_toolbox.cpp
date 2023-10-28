#include <vector>
#include <iostream>


class Neuron {
public:

	std::vector <Neuron> links;
	std::vector <int> weights;

	Neuron(std::vector <Neuron> links_, std::vector <int> weights_) {
		links = links_;
		weights = weights_;
	}
};

class Network {
public:

	Network() {

	}
};
