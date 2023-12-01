#include "Day1.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "Utils.h"

struct Word
{
	std::string word;
	std::uint64_t value;
	std::uint32_t index;
};

Word find_word(const std::string line, bool backwards = false)
{
	std::vector<Word> words = {
		{"one", 1, 0},
		{"two", 2, 0},
		{"three", 3, 0},
		{"four", 4, 0},
		{"five", 5, 0},
		{"six", 6, 0},
		{"seven", 7, 0},
		{"eight", 8, 0},
		{"nine", 9, 0}
	};
	Word word;
	word.index = 9999999999;
	for (auto& w : words)
	{
		if (backwards)
			std::reverse(w.word.begin(), w.word.end());
		std::size_t found = line.find(w.word);
		if (found != std::string::npos && found < word.index)
		{
			word = w;
			word.index = found;
		}
	}
	return word;
}

void Day_1()
{
	std::ifstream file("Day1.txt");
	if (file.is_open())
	{
		std::uint64_t total_sum = 0;
		std::string line;
		while (std::getline(file, line))
		{
			std::string sum;
			std::size_t first = line.find_first_of("0123456789");
			Word word = find_word(line);
			if (word.index < first)
				sum.push_back(word.value + '0');
			else
				sum.push_back(line[first]);
			std::reverse(line.begin(), line.end());
			std::size_t last = line.find_first_of("0123456789");
			word = find_word(line, true);
			if (word.index < last)
				sum.push_back(word.value + '0');
			else
				sum.push_back(line[last]);
			total_sum += std::stoull(sum);
		}
		std::cout << "Total: " << total_sum << "\n";
		file.close();
	}
}
