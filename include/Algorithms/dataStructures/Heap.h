#pragma once
#include <vector>
#include <optional>

template<typename T>
struct HeapNode {
	T data_;
	int prior_;
};

template<typename T>
struct BinaryHeap {
	explicit BinaryHeap(int maxsize);
	~BinaryHeap() = default;
	void Swap(size_t a, size_t b); // Обмен по индексам
	std::optional<T> FetchPriorityElement(); // Значение самого приоритетного
	void Insert(HeapNode<T> node); // Вставляем элемент
	void Heapify(size_t index); // Восстановление целостности
	void ExtractPriorityElement(); // Удаление приоритетного

private:
	std::vector<HeapNode<T>> body_;
	size_t size_;
	size_t capacity_;
};


template<typename T>
void BinaryHeap<T>::Swap(size_t a, size_t b)
{
	std::swap(body_[a], body_[b]);
}

template<typename T>
BinaryHeap<T>::BinaryHeap(int maxsize)
{
	body_.resize(maxsize);
	capacity_ = maxsize;
	size_ = 0;
}

template<typename T>
std::optional<T> BinaryHeap<T>::FetchPriorityElement()
{
	return size_ == 0 ? std::nullopt : std::optional<T>(body_[1].data_);
}

template<typename T>
void BinaryHeap<T>::Insert(HeapNode<T> node)
{
	if(size_  > capacity_)
		body_.resize(capacity_*2);

	body_[++size_] = node;
	for(size_t i = size_; i > 1 && body_[i].prior_ > body_[i/2].prior_; i /= 2) {
		Swap(i, i / 2);
	}
}

template<typename T>
void BinaryHeap<T>::Heapify(size_t index)
{
	while(true) {
		size_t left = 2*index;
		size_t right = left + 1;
		size_t largest = index;

		if(left <= size_ && body_[left].prior_ > body_[index].prior_)
			largest = left;
		if(right <= size_ && body_[right].prior_ > body_[largest].prior_)
			largest = right;
		if(largest == index)
			break;
		Swap(index, largest);
		index = largest;
	}
}

template<typename T>
void BinaryHeap<T>::ExtractPriorityElement()
{
	Swap(1, size_);
	size_--;
	Heapify(1);
}