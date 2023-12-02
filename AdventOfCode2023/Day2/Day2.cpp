#include "Day2.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#define RED		12
#define GREEN	13
#define BLUE	14

void Day_2()
{
	std::ifstream file("Input/Day2/Day2.txt");
	if (file.is_open())
	{
		int current_game = 1;
		std::uint64_t total_sum = 0;
		std::uint64_t total_sum2 = 0;
		std::string line;
		while (std::getline(file, line))
		{
			std::map<std::string, int> bag_map = {
				{"red", 0},
				{"green", 0},
				{"blue", 0}
			};
			std::string start = line.substr(line.find_first_of(':') + 2, line.size());

			std::istringstream ss(start);
			std::string token;
			while (std::getline(ss, token, ';'))
			{
				std::istringstream token_ss(token);
				std::string element;
				while (std::getline(token_ss, element, ','))
				{
					if (element[0] == ' ')
						element = element.substr(1, element.size());
					std::istringstream element_ss(element);
					int amount;
					std::string color;
					element_ss >> amount >> color;
					bag_map[color] = std::max(bag_map[color], amount);
				}
			}
			if (bag_map["red"] <= RED && bag_map["green"] <= GREEN && bag_map["blue"] <= BLUE)
			{
				printf("WON: Game: %i, bag: %i -> %i -> %i\n", current_game, bag_map["red"], bag_map["green"], bag_map["blue"]);
				total_sum = total_sum + current_game;
			}
			total_sum2 += bag_map["red"] * bag_map["green"] * bag_map["blue"];

			current_game++;
		}
		printf("Total sum: %i\n", total_sum);
		printf("Total sum part2: %i\n", total_sum2);
	}
}
