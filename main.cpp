#include <Algorithms/dataStructures/Trie.h>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::string;

int main()
{

	vector<string> strings = {"baba", "abba", "mamba"};

	trees::Trie trie;

	for(auto& string : strings)
		trie.AddString(string);

	trie.PrintTrie();

	return 0;
}