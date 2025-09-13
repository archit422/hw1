#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
    if (tail_ == NULL)
    {
      // allocate new item

      tail_ = new Item();
      head_ = tail_;

      tail_-> first = 0;
      tail_-> last  = 0;

      tail_-> prev = NULL;
      tail_-> next = NULL;
    }

    if (tail_->last == ARRSIZE)
    {

      Item* p = new Item();
      p-> first = 0;
      p-> last  = 0;

      p-> prev = tail_;
      p-> next = NULL;
      tail_-> next = p;
      tail_ = p;
    }

    tail_->val[tail_->last] = val;
    tail_ ->last += 1;
    size_ += 1;
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */


  void ULListStr::pop_back()
  {
    if (tail_ == NULL)
    {
      return;
    }

    tail_->last-=1;
    size_-= 1;

    if (tail_->last == tail_->first)
    {
      //deallocate item
      Item* to_delete = tail_;
      tail_ = tail_->prev;

      if(tail_ == nullptr)
      {
        head_ = NULL;
      }
      else
      {
        tail_->next = NULL;
      }
      delete to_delete;
    }
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */




  void ULListStr::push_front(const std::string& val)
  { 
    if (head_ == NULL)
    {  
      head_ = new Item();

      head_ -> first = ARRSIZE;
      head_ -> last  = ARRSIZE;

      head_ -> prev = NULL;
      head_ -> next = NULL;

      tail_ = head_;
    }

    if (head_->first == 0)
    {

      Item* p = new Item();
      p-> first = ARRSIZE;
      p-> last  = ARRSIZE;

      p-> next = head_;
      p-> prev = NULL;
      head_-> prev = p;
      head_ = p;
    }

    head_->first -= 1;
    head_->val[head_->first] = val;
    size_ += 1;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front()
  {

    if (head_ == NULL)
    {
      return;
    }

    head_->first +=1;
    size_-= 1;

    if (head_->last == head_->first)
    {
      //deallocate item
      Item* to_delete = head_;
      head_ = head_->next;

      if(head_ == nullptr)
      {
        tail_ = NULL;
      }
      else
      {
        head_->prev = NULL;
      }
      delete to_delete;
    }
  }
  

std::string& ULListStr::back() 
{
  if(empty()) throw std::out_of_range("back() on empty ULListStr");
  return tail_->val[tail_->last -1];
}

const std::string& ULListStr::back() const
{
  if(empty()) throw std::out_of_range("back() on empty ULListStr");
  return tail_->val[tail_->last -1];
}

std::string& ULListStr::front()
{
  if(empty()) throw std::out_of_range("front() on empty ULListStr");
  return head_->val[head_->first];
}

const std::string& ULListStr::front() const
{

  if(empty()) throw std::out_of_range("front() on empty ULListStr");
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}




 /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const
  {
    if(loc >= size_) 
    {
      return NULL;
    }

    Item* cur = head_;
    size_t location = loc;

    while(cur != NULL)
    {
      size_t u = cur->last - cur->first;
      if(location < u)
      {
        return &cur->val[cur->first + location];
      }

      location -= u;
      cur = cur->next;

    }
    return NULL;

  }

