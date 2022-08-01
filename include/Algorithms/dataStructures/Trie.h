#pragma once
#include <string>
#include <iostream>

namespace trees{
	const int kLetters = 26;


	class Trie {
	private:
		struct Vertex{
			Vertex* to[kLetters] = {nullptr};
			bool isTerminal = false;
		};

		Vertex* root_;

		void DFS(Vertex* v) {
			if(v->isTerminal) {
				std::cout << "\n";
				return;
			}

			for(int i = 0; i < kLetters; ++i) {
				if(v->to[i]) {
					std::cout << char('a'+i);
					DFS(v->to[i]);
				}
			}
		}

	public:
		Trie() : root_(new Vertex())
		{}

		void AddString(const std::string& s) {
			auto v = root_;

			for(auto c : s) {
				c -= 'a';
				if(!v->to[c])
					v->to[c] = new Vertex();
				v = v->to[c];
			}

			v->isTerminal = true;
		}

		bool Find(const std::string& s) {
			auto v = root_;

			for(auto c : s) {
				c -= 'a';
				if(!v->to[c])
					return false;
				v = v->to[c];
			}

			return v->isTerminal;
		}

		bool Erase(const std::string& s) {
			auto v = root_;

			for(auto c : s)
				v = v->to[c-'a'];
			v->isTerminal = false;
		}

		void PrintTrie() {
			std::cout << "Our trie:\n\n";
			DFS(root_);
		}

	};
}