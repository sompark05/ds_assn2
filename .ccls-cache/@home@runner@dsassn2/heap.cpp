#include "heap.h"
#include <iostream>
#include <string>

using namespace std;

string PriorityQueue::printPQ() {
  string answer;
  for (int i = 0; i < size; i++)
    answer += to_string(heap[i].value) + " ";
  return answer;
}

bool PriorityQueue::insert(int priority, int value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  // if priority queue is full, return 0 (ERROR)
  if (size == 99) {
    return 0;
  }

  pq_element *p_element = new pq_element;
  p_element->priority = priority;
  p_element->value = value;

  if (empty()) {
    heap[0] = *p_element;
    size++;
    return true;
  }

  heap[size] = *p_element;
  size++;

  upHeapBubble(priority, size - 1);

  return true;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

bool PriorityQueue::removeMax() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (empty()) {
    return false;
  }

  // replace the root node with the last leaf node
  heap[0] = heap[size - 1];
  size--;
  downHeapBubble(heap[0].priority, 0);
  return true;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

pq_element PriorityQueue::getMax() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  return heap[0];
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

bool PriorityQueue::empty() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (size > 0) {
    return false;
  }
  return true;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

bool PriorityQueue::changeMax(int target) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  for (int i = 0; i < size; i++) {
    if (heap[i].value == target) {
      swap(heap[i], heap[0]);
      heap[0].priority = heap[i].priority + 1;
      heap[0].value = heap[i].value + 1;

      upHeapBubble(heap[i].priority, i);
      return true;
    }
  }
  return false;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  You can implement any other functions ////////

bool PriorityQueue::findElement(int priority) {
  for (int i = 0; i < size; i++) {
    if (heap[i].priority == priority) {
      return true;
    }
  }
  return false;
}

void PriorityQueue::downHeapBubble(int priority, int index) {
  if (index >= size) {
    return;
  }
  int left_index = (index + 1) * 2 - 1;
  int right_index = (index + 1) * 2;

  if (heap[index].priority >= heap[left_index].priority &&
      heap[index].priority >= heap[right_index].priority) {
    return;
  }

  if (heap[index].priority < heap[left_index].priority &&
      heap[right_index].priority < heap[left_index].priority) {
    swap(heap[index], heap[left_index]);
  } else if (heap[index].priority < heap[right_index].priority &&
             heap[left_index].priority < heap[right_index].priority) {
    swap(heap[index], heap[right_index]);
  }
}

void PriorityQueue::upHeapBubble(int priority, int index) {
  if (index == 0) {
    return;
  }
  if (heap[index].priority < heap[(index - 1) / 2].priority) {
    return;
  }
  swap(heap[index], heap[(index - 1) / 2]);
  upHeapBubble(priority, ((index - 1) / 2));
  return;
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
