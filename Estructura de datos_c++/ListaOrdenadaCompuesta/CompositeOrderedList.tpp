
/*
    \Name: CompositeOrderedList.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/20/21
    \brief: Template file where the functions and operators of the CompositeOrderedList
            class are declared
*/

template <typename T>
CompositeOrderedList<T>::CompositeOrderedList(){
}
//*****************************************************//
template <typename T>
CompositeOrderedList<T>::CompositeOrderedList(const CompositeOrderedList<T> &l){
*this = l;
}
//*****************************************************//
template <typename T>
CompositeOrderedList<T>::~CompositeOrderedList(){
}
//*****************************************************//
template <typename T>
CompositeOrderedList<T>& CompositeOrderedList<T>::operator=(const CompositeOrderedList<T> &l){
    if(this == &l) return *this;
    OrderedList = l.OrderedList;
    return *this;
}

//*****************************************************//
template <typename T>
void CompositeOrderedList<T>::Push(const T& value){
    OrderedList.Push_Front(value);
    OrderedList.SortAscending();
}
//*****************************************************//
template <typename T>
void CompositeOrderedList<T>::Pop(const T& val){
    if(Empty()) throw EmptyList();
    OrderedList.DeleteElement(val);
}
//*****************************************************//
template <typename T>
bool CompositeOrderedList<T>::Search(const T& val) const{
    return OrderedList.Search(val);
}
//*****************************************************//
template <typename T>
void CompositeOrderedList<T>::Clear(){
    OrderedList.Clear();
}
//*****************************************************//
template <typename T>
unsigned CompositeOrderedList<T>::Size() const{
    return OrderedList.Size();
}

//*****************************************************//
template <typename T>
bool CompositeOrderedList<T>::Empty() const{
    return OrderedList.Empty();
}
//*****************************************************//
template <typename T>
void CompositeOrderedList<T>::Print() const{
    OrderedList.Print();
}
//*****************************************************//
template <typename T>
void CompositeOrderedList<T>::ReversePrint() const{
    OrderedList.ReversePrint();
}//*****************************************************//

template <typename T>
const char* CompositeOrderedList<T>::EmptyList::what() const throw(){
    return "Empty List...";
}
