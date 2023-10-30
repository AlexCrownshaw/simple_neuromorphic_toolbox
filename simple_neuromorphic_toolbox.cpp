#include <vector>
#include <iostream>


struct Epoch	{
	double learning_eff {};

};

class Node {
private:

	std::vector <Node> links;
	std::vector <double> weights;

public:

	// links.getter
	std::vector <Node> getLinks()	{
		return links;
	}

	// links.setter
	void setLinks(std::vector <Node> value)	{
		links = value;
	}

	// weights.getter
	std::vector <double> getWeights()	{
		return weights;
	}

	// weights.setter
	void setWeights(std::vector <double> value)	{
		weights = value;
	}
};

class Network {
private:

	std::vector <int> structure;
	std::vector <std::vector<Node>> nodes {};
	std::vector <std::vector<double>> inputs {};
	std::vector <std::vector<double>> exp_outputs {};

public:

	Network(std::vector <int> structure_value) {
		structure = structure_value;
		createNetwork();
	}

	void createNetwork()	{
		for (int i_layer {}; i_layer < structure.size(); i_layer++)	{

			// Create Node objects for layer
			std::vector <Node> layer_nodes {};
			for (int i_node {0}; i_node < structure.at(i_layer); i_node++)	{
				layer_nodes.push_back(Node());
			}
			nodes.push_back(layer_nodes);

			// Attach Node objects and weights to previous layer
			if (i_layer != 0)	{
				for (int i_node {0}; i_node < nodes.at(i_layer - 1).size(); i_node++)	{
					nodes.at(i_layer - 1).at(i_node).setLinks(nodes.at(i_layer));
					std::vector<double> weights(nodes.at(i_layer).size(), 1.f);
					nodes.at(i_layer - 1).at(i_node).setWeights(weights);
				}
			}
		}
	}

	Epoch runEpoch()	{
		Epoch epoch;
		return epoch;
	}

	// structure.getter
	std::vector <int> getStructure()	{
		return structure;
	}

	// nodes.getter
	std::vector <std::vector<Node>> getNodes()	{
		return nodes;
	}

	// inputs.setter
	void setInputs(std::vector <std::vector<double>> value)	{
		inputs = value;
	}

	// inputs.getter
	std::vector <std::vector<double>> getInputs()	{
		return inputs;
	}

	// exp_outputs.setter
	void setExpOutputs(std::vector <std::vector<double>> value)	{
		exp_outputs = value;
	}

	// exp_outputs.getter
	std::vector <std::vector<double>> getExpOutputs()	{
		return exp_outputs;
	}
};
