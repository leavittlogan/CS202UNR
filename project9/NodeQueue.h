#ifndef NODEQUEUE_H_
#define NODEQUEUE_H_

#include <iostream>
#include "DataType.h"

class Node {

	friend class NodeQueue;  //allows direct accessing of link and data from class NodeList
  
	public:
		Node() : m_next( NULL ) {}

		Node(const DataType & data, Node * next = NULL) :
			m_next( next ),
			m_data( data ) {}

		Node(const Node & other) :
			m_next( other.m_next ),
			m_data( other.m_data ) {}
	
		DataType & data() {  //gets non-const reference
			return m_data;
		}

		const DataType & data() const {  //gets const reference
			return m_data;
		}

	private:
		Node * m_next; 						
		DataType m_data;
};
 
class NodeQueue {

	friend std::ostream & operator<<(std::ostream & os,
			const NodeQueue & nodeQueue);

	public:
		NodeQueue();
		NodeQueue(size_t size, const DataType & value);
		NodeQueue(const NodeQueue & other);
		~NodeQueue();

		NodeQueue & operator=(const NodeQueue & rhs);

		DataType & front();
		const DataType & front() const;

		DataType & back();
		const DataType & back() const;

		void push(const DataType & value);
		void pop();

		size_t size() const;
		bool empty() const;
		bool full() const;
		void clear();
		void serialize(std::ostream & os) const;

	private:
		Node * m_front;
		Node * m_back;
};

#endif // NODEQUEUE_H_
