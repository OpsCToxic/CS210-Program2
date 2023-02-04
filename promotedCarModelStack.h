#ifndef PROMOTEDCARMODELSTACK_H
#define PROMOTEDCARMODELSTACK_H

#include <ctype.h>  // character manipualtion, e.g. tolower()
#include <stdio.h> 
#include <string>
#include <utility>

using namespace std;

template<typename T>
class Node {
public:
  T node;
  Node<T>* nextPtr;
  
  Node(T car) {
      node = car;
      nextPtr = nullptr;
  }
  
};

template<typename T>
class LinkedList {
    
  public:
    Node<T>* head;
    Node<T>* tail;
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    Node<T>* getHeadNode() const {
      return head;
    }
    void setHeadNode(Node<T>* headNode) {
      head = headNode;
    }
    Node<T>* getTailNode() const {
      return tail;
    }
    void setTailNode(Node<T>* tailNode) {
      tail = tailNode;
    }

};



class PromotedModel {

private:
  string model;
  int promotedPrice;

public:
  PromotedModel() {
    this -> model = "";
    this -> promotedPrice = -1;
  }

  PromotedModel(string m, int p) {
    this -> model = m;
    this -> promotedPrice = p;
  }

  inline string getModel() {
    return model;
  }

  inline int getPromotedPrice() {
    return promotedPrice;
  }
};

class PromotedCarModelStack {

private:  
  // TODO: add member variables as needed
  LinkedList<PromotedModel> carModelStack;
  LinkedList<pair<PromotedModel, PromotedModel>> lowAndHighList;

public:
  /**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param model 
   * @param price 
   */
  void push(string model, int price);
  
  /**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param  
   * @return PromotedModel
   *         should throw a logic_error exception with an error message 
   *         “Promoted car model stack is empty” if the PromotedCarModelStack is empty
   */
  PromotedModel pop();

  /**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1) 
   * @param 
   * @return PromotedModel
   *         should throw a logic_error exception with an error message 
   *         “Promoted car model stack is empty” if the PromotedCarModelStack is empty
   */
  PromotedModel peek();

  /**
   * @brief getHighestPricedPromotedModel, 
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   *         should throw a logic_error exception with an error message 
   *         “Promoted car model stack is empty” if the PromotedCarModelStack is empty
   */
  PromotedModel getHighestPricedPromotedModel();

  /**
   * @brief getLowestPricedPromotedModel, 
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   *         should throw a logic_error exception with an error message 
   *         “Promoted car model stack is empty” if the PromotedCarModelStack is empty
   */
  PromotedModel getLowestPricedPromotedModel();


};

#endif