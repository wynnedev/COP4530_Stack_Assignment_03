template <typename T>
List<T>::const_iterator::const_iterator()
{
    current = nullptr;
}

template <typename T>
const T& List<T>::const_iterator::operator*() const
{
    return this->retrieve();
}

template <typename T>
T& List<T>::iterator::operator*()
{
    return this->retrieve();
}

template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
    const_iterator old = *this;
    ++(*this);
    return old;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
    iterator old = *this;
    ++(*this);
    return old;
}

template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--()
{
    this->current = this->current->prev;
    return *this;
}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator--()
{
    this->current = this->current->prev;
    return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{
    const_iterator old = *this;
    --(*this);
    return old;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{
    const_iterator old = *this;
    --(*this);
    return old;
}

template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{
    return current == rhs.current;
}

template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{
    return current != rhs.current;
}

template <typename T>
List<T>::const_iterator::const_iterator(List<T>::Node *p)
{
    current = p;
}

template <typename T>
T& List<T>::const_iterator::retrieve() const
{
    return this->current->data;
}

template <typename T>
List<T>::iterator::iterator()
{ 
    this->current = nullptr;
}

template <typename T>
List<T>::iterator::iterator(List<T>::Node *p)
{ 
    this->current = p;
}

template <typename T>
void List<T>::init()
{
    theSize=0;
    head = new List::Node;
    tail = new List::Node;
    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;
}

template <typename T>
List<T>::List()
{
    init();
}

template <typename T>
List<T>::List(const_iterator start, const_iterator end)
{
    this->init();
    while(start != end)
    {
        this->push_back(*start);
        ++start;
    }
}

template <typename T>
List<T>::List(const List<T> &rhs)
{
    this->init();
    for ( List<T>::iterator itr = begin(); itr != end();)
    {   
        this->push_back(*itr);
        ++itr;
    }
}

template <typename T>
const List<T>& List<T>::operator=(const List<T> &rhs)
{
    this->clear();
    for ( List<T>::const_iterator itr = rhs.begin(); itr != rhs.end();)
    {   
        this->push_back(*itr);
        ++itr;
    }

    return *this;
}

template <typename T>
List<T>& List<T>::operator= (std::initializer_list<T> iList)
{
    this->init();
    auto start = iList.begin();
    auto end = iList.end();

    while(start != end)
    {
        this->push_back(*start);
        ++start;
    }
    return *this;
}

template <typename T>
List<T>::List(List<T> &&rhs)
{
    this->theSize = rhs.theSize;
    this->head = rhs.head;
    this->tail = rhs.tail;
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template <typename T>
List<T>::List(int num, const T& val)
{
    this->init();

    while(num--)
    {
        push_back(val);
    }
}

template <typename T>
List<T>::List(std::initializer_list<T> iList)
{
    this->init();
    auto start = iList.begin();
    auto end = iList.end();

    while(start != end)
    {
        this->push_back(*start);
        ++start;
    }
}

template <typename T>
List<T>& List<T>::operator=(List<T> &&rhs)
{
    std::cout << "List<T>& List<T>::operator=(List<T> &&rhs)" <<std::endl;
    std::swap( theSize, rhs.theSize );
    std::swap( head, rhs.head );
    std::swap( tail, rhs.tail );
    return *this;
}

template <typename T>
int List<T>::size() const
{
    return theSize;
}

template <typename T>
bool List<T>::empty() const
{
    if(theSize <= 0)
    {
        return true;
    }
    return false;
}

template <typename T>
T& List<T>::front()
{
    return *begin();
}

template <typename T>
const T& List<T>::front() const
{
    return *begin();
}

template <typename T>
T& List<T>::back()
{
    return *--end();
}

template <typename T>
void List<T>::push_front(const T& val)
{
    insert(begin(), val);
}

template <typename T>
void List<T>::push_front(T&& val)
{
    insert(begin(), std::move(val));
}

template <typename T>
void List<T>::push_back(const T& val)
{
    insert(end(), val);
}

template <typename T>
void List<T>::push_back(T&& val)
{
    insert(end(), std::move(val));
}

template <typename T>
void List<T>::pop_front()
{
    erase( begin());
}

template <typename T>
void List<T>::pop_back()
{
    erase( --end());
}

template <typename T>
const T& List<T>::back() const
{
    return *--end();
}

template <typename T>
typename List<T>::iterator List<T>::begin()
{
    return ( head->next );
}

template <typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    return ( head->next );
}

template <typename T>
typename List<T>::iterator List<T>::end()
{
    return ( tail );
}

template <typename T>
typename List<T>::const_iterator List<T>::end() const
{
    return ( tail );
}

template <typename T>
typename List<T>::iterator List<T>::insert( List<T>::iterator itr, const T& val)
{
    Node *p = itr.current;
    theSize++;
    return { p->prev = p->prev->next = new Node{ val, p->prev, p }};
}

template <typename T>
typename List<T>::iterator List<T>::insert( List<T>::iterator itr, T&& val)
{
    Node *p = itr.current;
    theSize++;
    return { p->prev = p->prev->next = new Node { std::move(val), p->prev, p }};
}

template <typename T>
typename List<T>::iterator List<T>::erase(List<T>::iterator itr)
{
    Node *p = itr.current;
    iterator retVal{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;

    return retVal;
}

template <typename T>
void List<T>::remove(const T& val)
{
    auto current = this->begin();
    auto end = this->end();

    while(current != end)
    {
        if(*current == val)
        {
            std::cout << "Test Print Before:" << std::endl;
            this->print(std::cout);
            std::cout << std::endl;
            current = erase(current);
            this->print(std::cout);
            std::cout << "\nTest Print End: " << std::endl;
        }
        
        else
        {
            ++current;
        }  
    }
    this->print(std::cout);
}

template <typename T>
void List<T>::print(std::ostream& os, char ofc) const
{
    for ( const_iterator itr = begin(); itr != end();)
    {
        os << *itr << ofc;
        ++itr;
    }
}

template <typename T>
typename List<T>::iterator List<T>::erase(List<T>::iterator start, List<T>::iterator end)
{
    for ( List<T>::iterator itr = start; itr != end; )
    {
        itr = erase( itr );
    }

    return end;
}

template <typename T>
void List<T>::clear()
{
    if(!empty())
    {
       erase(begin(), end()); 
    }   
}

template <typename T>
void List<T>::reverse()
{
    List<T>::iterator tail = end();
    List<T>::iterator current = begin();
    List<T> temp;

    while(current != tail)
    {
        temp.push_front(*current);
        current++;
    }

    *this = temp;
}

template <typename T>
template <typename PREDICATE>
void List<T>::remove_if(PREDICATE pred)
{
    for ( List<T>::iterator itr = begin(); itr != end(); )
    {
        if(pred(*itr))
        {
            itr = erase(itr);
        }

        else
        {
            ++itr;
        }  
    }
}


template <typename T>
List<T>::~List()
{
    delete head;
    delete tail;
}

template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{
    if(lhs.size() == rhs.size())
    {
        auto lhsStart = lhs.begin();
        auto lhsEnd = lhs.end();
        auto rhsStart = rhs.begin();


        while(lhsStart != lhsEnd)
        {
            if(*lhsStart == *rhsStart)
            {
                ++lhsStart;
                ++rhsStart;
            }
            
            else
            {
                return false;
            }  
        }
        return true;
    }
    return false;
}

template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
    return !(lhs==rhs);
}



