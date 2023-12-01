#include <fstream>
#include <iostream>
#include <regex>

std::vector<std::tuple<std::string, int>> replacements = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}};

int first_digit(std::string line);
int last_digit(std::string line);

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int sum = 0;

    while (std::getline(input, line))
    {
        auto first = first_digit(line);
        auto last = last_digit(line);
        sum += 10 * first + last;
    }

    std::cout << sum << std::endl;
}

int first_digit(std::string line)
{
    std::string prefix = "";

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            return line[i] - '0';
        }
        else
        {
            prefix += line[i];
            for (auto replacement : replacements)
            {
                if (prefix.find(std::get<0>(replacement)) != std::string::npos)
                {
                    return std::get<1>(replacement);
                }
            }
        }
    }
    return -1;
}

int last_digit(std::string line)
{
    std::string suffix = "";

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            return line[i] - '0';
        }
        else
        {
            suffix.insert(0, 1, line[i]);
            for (auto replacement : replacements)
            {
                if (suffix.find(std::get<0>(replacement)) != std::string::npos)
                {
                    return std::get<1>(replacement);
                }
            }
        }
    }
    return -1;
}