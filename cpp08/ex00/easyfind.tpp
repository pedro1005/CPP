#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <class T>
typename T::iterator easyfind(T& t, int x) {
    typename T::iterator it = std::find(t.begin(), t.end(), x);
    if (it == t.end())
        throw std::runtime_error("Value not found in container.");
    return it;
}

#endif
