#pragma once

#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>

namespace trees {

	template<typename T>
	class Trie {
	public:
		template<typename It>
		void Insert(It it, It end_it) {
			if(it == end_it)
				return;
			tries_[*it].Insert(std::next(it), end_it);
		}

		template<typename C>
		void Insert(const C& container) {
			Insert(std::begin(container), std::end(container));
		}

		void Insert(const std::initializer_list<T>& il) {
			Insert(il.begin(), il.end());
		}

		void Print(std::vector<T>& v) const {
			if(tries_.empty()) {
				std::copy(v.begin(), v.end(),
					std::ostream_iterator<T>{std::cout, " "});
				std::cout << '\n';
			}
			for(const auto& p : tries_) {
				v.push_back(p.first);
				p.second.Print(v);
				v.pop_back();
			}
		}

		void Print() const {
			std::vector<T> v;
			Print(v);
		}

		template<typename It>
		std::optional<std::reference_wrapper<const Trie>>
			Subtrie(It it, It end_it) const {
			if(it == end_it)
				return ref(*this);
			auto found (tries_.find(*it));
			if(found == end(tries_))
				return {};
			return found->second.Subtrie(std::next(it), end_it);
		}

		template<typename C>
		auto Subtrie(const C& c) {
			return Subtrie(c.begin(), c.end());
		}

		private:
		std::map<T, Trie> tries_;
	};
}