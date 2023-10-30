#include <vector>
#include <iostream>

// class Node;

// struct Link {
// public:

//     Node node;
//     double weight;

// };

class Node {
private:

	// std::vector <Link> links;
	std::vector <Node> links;
	std::vector <double> weights;

public:

	// // links.getter
	// std::vector <Link> getLinks()	{
	// 	return links;
	// }

	// links.getter
	std::vector <Node> getLinks()	{
		return links;
	}

	// // links.setter
	// void setLinks(std::vector <Node> node_values, std::vector <double> weight_values)	{
	// 	links.reserve(node_values.size());
	// 	for (size_t i_node; i_node < node_values.size(); i_node++)	{
	// 		links.at(i_node) = Link();
	// 		links.at(i_node).node = node_values.at(i_node);
	// 		links.at(i_node).weight = weight_values.at(i_node);
	// 	}
	// }

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
public:
	std::vector <int> structure;
	std::vector <std::vector<Node>> nodes {};

// public:

	Network(std::vector <int> structure_value) {
		structure = structure_value;

		// Pre-allocate size of layer/node vectors
		// nodes.reserve(structure.size());
		for (int i_layer {}; i_layer < structure.size(); i_layer++)	{
			// nodes.at(i_layer).reserve(structure.at(i_layer));

			// Create Node objects for layer
			std::vector <Node> layer_nodes {};
			for (int i_node {0}; i_node < structure.at(i_layer); i_node++)	{
				// nodes.at(i_layer).at(i_node) = Node();
				layer_nodes.push_back(Node());
			}
			nodes.push_back(layer_nodes);

			// Attach Node objects to previous layer as Link structs
			if (i_layer != 0)	{
				for (int i_node {0}; i_node < nodes.at(i_layer - 1).size(); i_node++)	{
					nodes.at(i_layer - 1).at(i_node).setLinks(nodes.at(i_layer));
					std::vector<double> weights(nodes.at(i_layer).size(), 1.f);
					nodes.at(i_layer - 1).at(i_node).setWeights(weights);
					// nodes.at(i_layer - 1).at(i_node).setLinks(nodes.at(i_layer), weights);
				}
			}
		}
	}
};
