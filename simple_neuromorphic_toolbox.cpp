#include <vector>
#include <iostream>
#include <String>
#include <cmath>

struct Result	{
	std::vector <double> output;
	double learn_acc;
};

struct Epoch	{
	double learn_eff;
	double learn_acc;
	std::vector <Result> results;
};

class Node {
private:

	int activation_func {};

	std::vector <Node *> p_links;
	std::vector <double> weights;

	double value;
	std::vector <double> input_buffer;

	double sigmoid(double x)	{
		return 1 / (1 + exp(-x));
	}

public:

	void forwardValue()	{
		for (int i_link {}; i_link < p_links.size(); i_link++)	{
			p_links.at(i_link)->setBuffer(value * weights.at(i_link));
		}
	}

	void computeInput()	{
		double input_sum {};
		for (int i_input {}; i_input < input_buffer.size(); i_input++)	{
			input_sum += input_buffer.at(i_input);
		}

		if (activation_func == 0)	{
			value = sigmoid(input_sum);
		}

		input_buffer.clear();
	}

	// links.getter
	std::vector <Node> getLinks()	{
		std::vector <Node> links;
		for (int i_link {}; i_link < p_links.size(); i_link++)	{
			links.push_back(*p_links.at(i_link));
		}

		return links;
	}

	// links.setter
	void setLinks(std::vector <Node *> value)	{
		p_links = value;
	}

	// weights.getter
	std::vector <double> getWeights()	{
		return weights;
	}

	// weights.setter
	void setWeights(std::vector <double> value)	{
		weights = value;
	}

	// weights.setter
	void setActivationFunc(int value)	{
		activation_func = value;
	}

	// input_buffer.setter
	void setBuffer(double value)	{
		input_buffer.push_back(value);
	}

	// value.getter
	double getValue()	{
		return value;
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

	std::vector <double> initWeights(int size) {
	// return a vetor of uniformly distributed random values of length 'size'
	std::vector <double> weights;
	for (int i_weight {}; i_weight < size; i_weight++)	{
			weights.push_back(((double)(rand()) + 1.)/((double)(RAND_MAX) + 1.));
	}
		
		return weights;
	}

	void createNetwork()	{
		for (int i_layer {}; i_layer < structure.size(); i_layer++)	{

			// Create Node objects for each layer
			std::vector <Node> layer_nodes {};
			for (int i_node {0}; i_node < structure.at(i_layer); i_node++)	{
				layer_nodes.push_back(Node());
			}
			nodes.push_back(layer_nodes);

			// Attach Node objects and weights to previous layer
			if (i_layer != 0)	{
				for (int i_node {0}; i_node < nodes.at(i_layer - 1).size(); i_node++)	{
					// Create vector of Node pointers to linked nodes
					std::vector <Node *> p_links;
					for (int i_link {}; i_link < nodes.at(i_layer).size(); i_link++)	{
						p_links.push_back(&nodes.at(i_layer).at(i_link));
					}
					nodes.at(i_layer - 1).at(i_node).setLinks(p_links);
					std::vector<double> weights {initWeights(nodes.at(i_layer - 1).size())};
					nodes.at(i_layer - 1).at(i_node).setWeights(weights);
				}
			}
		}
	}

	std::vector <Epoch> run(int n_epoch)	{
		std::vector <Epoch> epochs {};
		for (int i_epoch {}; i_epoch < n_epoch; i_epoch++)	{
			epochs.push_back(runEpoch());
		}

		return epochs;
	}

	Result evalResult(std::vector <double> output, std::vector <double> exp_output)	{
		Result result;
		result.output = output;

		for (int i_output {}; i_output < output.size(); i_output++)	{
			if (output.at(i_output) == exp_output.at(i_output))	{
				result.learn_acc += 1;
			}
		}
		result.learn_acc /= output.size();

		return result;
	}

	Epoch runEpoch()	{
		Epoch epoch;

		for (int i_input {}; i_input < inputs.size(); i_input++)	{
			std::vector <double> output;

			for (int i_layer {}; i_layer < nodes.size(); i_layer++)	{
				for (int i_node {}; i_node < nodes.at(i_layer).size(); i_node++)	{

					// Fill buffer of first nodes with inputs
					if (i_layer == 0)	{
						nodes.at(0).at(i_node).setBuffer(inputs.at(i_input).at(i_node));
					}

					// Build output vector
					else if (i_layer == nodes.size() - 1)	{
						output.push_back(nodes.at(i_layer).at(i_node).getValue());
					}
										
					// Sum buffers, compute values and forward to linked nodes
					else {
						nodes.at(i_layer).at(i_node).computeInput();
						nodes.at(i_layer).at(i_node).forwardValue();
					}
				}

				// Compare output to expected output and compute output metrics
				if (i_layer == nodes.size() - 1)	{
					epoch.results.push_back(evalResult(output, exp_outputs.at(i_input)));
				}
			}
		}
		
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
