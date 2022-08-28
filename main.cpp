#include <Algorithms/dataStructures/Trie.h>
#include <Algorithms/dataStructures/Heap.h>
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using std::vector;
using std::cout;
using std::cin;
using std::string;

int main()
{

	/*vector<string> strings = {"baba", "abba", "mamba"};

	trees::Trie<string> trie;

	trie.Insert({"hi", "how", "are", "you"});
	trie.Insert({"hi", "i", "am", "fine"});
	trie.Insert({"what", "are", "you", "doing"});
	trie.Insert({"I", "am", "watching", "movie"});

	cout << "Recorded sentences: \n";
	trie.Print();

	cout << "\npossible suggestions after \"hi\" : \n";

	if(auto st(trie.Subtrie(std::initializer_list<string>{"hi"})); st) {
		st->get().Print();
	}
*/
	BinaryHeap<int> heap(10);

	for(int i = 0; i < 10; ++i) {
		int a; cin >> a;
		heap.Insert({a, a});
	}

	for(int i = 0; i < 10; ++i) {
		cout << heap.FetchPriorityElement().value() << '\n';
		heap.ExtractPriorityElement();
	}

	return 0;
}