#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;


/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
class MyQueue232 {
	list<int>s;
public:
	/** Initialize your data structure here. */
	MyQueue232() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s.push_back(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int res = peek();
		s.pop_front();
		return res;
	}

	/** Get the front element. */
	int peek() {
		int res = s.front();
		return res;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */




