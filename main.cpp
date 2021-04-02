#include <iostream>
#include <vector>
#include <string.h>
#include <set>

std::vector<std::string> mergeStringList(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>);

int main()
{
    std::vector<std::string> original{"one", "two", "three"};
    std::vector<std::string> add{"one", "two", "five", "six"};
    std::vector<std::string> del{"two", "five"};
    std::vector<std::string> result;

    result = mergeStringList(original, add, del);

    for (std::string it : result)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    original.clear();
    add.clear();
    del.clear();
    result.clear();

    original.push_back("a");
    add.push_back("a");
    original.push_back("b");
    original.push_back("z");
    original.push_back("c");
    original.push_back("aa");
    original.push_back("ab");
    original.push_back("az");
    original.push_back("ac");
    original.push_back("aaaaa");
    original.push_back("ba");
    original.push_back("za");
    add.push_back("aa");
    add.push_back("aa");
    del.push_back("aa");

    //result: aaaaa za ba az ac ab z c b a
    result = mergeStringList(original, add, del);

    for (std::string it : result)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

//Sets are implemented as Binary Trees, therefore, O(logn) insertion, deletion, and search
//Overall Time Complexity: nlogn, assuming n is the largest list
//Overall Space Complexity: n+m+o, where n = size of original, m = size of add, n = size of del
std::vector<std::string> mergeStringList(std::vector<std::string> original, std::vector<std::string> add, std::vector<std::string> del)
{
    std::vector<std::string> result;
    auto custom_compare = [](std::string a, std::string b) {
        if (a.length() == b.length()) //compare by length, then reverse alphabetical order
        {
            return a.compare(b) > 0;
        }
        else
        {
            return a.length() > b.length();
        }
    };
    std::set<std::string, decltype(custom_compare)> s;

    //Duplicates will be ignored (as this is a property of sets)
    for (std::string it : original)
    {
        s.insert(it);
    }

    for (std::string it : add)
    {
        s.insert(it);
    }

    for (std::string it : del)
    {
        s.erase(it);
    }

    for (std::string it : s)
    {
        result.push_back(it);
    }
    return result;
}