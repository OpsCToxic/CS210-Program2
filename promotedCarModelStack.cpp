#include "promotedCarModelStack.h"

/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param model 
   * @param price 
   */
void PromotedCarModelStack::push(string model, int price) {
  // Write your code
  PromotedModel newCar(model, price);
  Node<PromotedModel>* newNode = new Node<PromotedModel>(newCar);
  pair<PromotedModel, PromotedModel> lowHighPair;
  Node<pair<PromotedModel, PromotedModel>>* newLowHighNode;
  
  if (carModelStack.head == nullptr) {
    carModelStack.head = newNode;
    carModelStack.tail = newNode;

    lowHighPair = make_pair(newCar, newCar);
    newLowHighNode = new Node<pair<PromotedModel, PromotedModel>>(lowHighPair);

    lowAndHighList.head = newLowHighNode;
    lowAndHighList.tail = newLowHighNode;
  }
  else {
    
    if (price < lowAndHighList.head->node.first.getPromotedPrice()) {
      lowHighPair = make_pair(newCar, lowAndHighList.head->node.second);
      newLowHighNode = new Node<pair<PromotedModel, PromotedModel>>(lowHighPair);
    }
    else if (price > lowAndHighList.head->node.second.getPromotedPrice()) {
      lowHighPair = make_pair(lowAndHighList.head->node.first, newCar);
      newLowHighNode = new Node<pair<PromotedModel, PromotedModel>>(lowHighPair);
    }
    else {
      lowHighPair = make_pair(lowAndHighList.head->node.first, lowAndHighList.head->node.second);
      newLowHighNode = new Node<pair<PromotedModel, PromotedModel>>(lowHighPair);
    }
    newNode->nextPtr = carModelStack.head;
    carModelStack.head = newNode;
    newLowHighNode->nextPtr = lowAndHighList.head;
    lowAndHighList.head = newLowHighNode;
  }
}

/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param  
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::pop() {
  // Write your code
  
  if (carModelStack.head == nullptr) {
    __throw_logic_error("Prompted car model stack is empty");
  }
  else {
    PromotedModel car = carModelStack.head->node;
    carModelStack.head = carModelStack.head->nextPtr;

    if (carModelStack.head == nullptr) {
      carModelStack.tail == nullptr;
    }
    
    
    lowAndHighList.head = lowAndHighList.head->nextPtr;
    
    return car;

  }
}

/**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1) 
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek() {
  
  if (carModelStack.head == nullptr) {
    __throw_logic_error("Prompted car model stack is empty");
  }
  else {
    PromotedModel car = carModelStack.head->node;
    return car;
  }
  
}

/**
   * @brief getHighestPricedPromotedModel, 
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel() {
  // Write your code
  pair<PromotedModel, PromotedModel> curLowAndHigh = lowAndHighList.head->node;
  return curLowAndHigh.second;

}

/**
   * @brief getLowestPricedPromotedModel, 
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel() {
  // Write your code
  pair<PromotedModel, PromotedModel> curLowAndHigh = lowAndHighList.head->node;
  return curLowAndHigh.first;

}


