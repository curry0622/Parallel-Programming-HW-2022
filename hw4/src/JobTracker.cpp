#include "JobTracker.hpp"

// Constructor
JobTracker::JobTracker(int num_nodes, std::string loc_config_file) {
    this->num_nodes = num_nodes;
    set_loc_config(loc_config_file);
}

// Methods
void JobTracker::set_loc_config(std::string loc_config_file) {
    std::ifstream fin(loc_config_file);
    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        int chunk_id, node_id;
        ss >> chunk_id >> node_id;
        node_id = (num_nodes % (num_nodes - 1)) + 1;
        loc_config[chunk_id] = node_id;
    }
}

// Utils
void JobTracker::print_loc_config() {
    for (const auto& p : loc_config) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}
