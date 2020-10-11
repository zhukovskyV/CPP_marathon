#pragma once

#include <utility>
#include <algorithm>

namespace Utils {
// [from, to]
    template<typename T>
    bool IsInRange(const T &val, const T &from, const T &to) {
        return (val >= from && val <= to);
    }

    template <typename T>
    bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
        return(val >= minmax.first && val <= minmax.second);
    }

    template <typename T>
    bool IsInsideRange(const T& val, const T& from, const T& to) {
        return (val > from && val < to);
    }

    template <typename T>
    bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
        return (val > minmax.first && val < minmax.second);
    }

    template <class T, class U = T>
    bool Modify(T& obj, U&& new_value) {
        if (obj == new_value)
            return false;
        obj = new_value;
        return true;
    }

    template <class Collection, class T>
    void RemoveAll(Collection& c, const T& value) {
        auto end = std::remove(c.begin(), c.end(), value);
        c.resize(std::distance(c.begin(), end));
    }

    template <class Collection, class Pred>
    void RemoveAllIf(Collection& c, Pred&& predicate) {
        auto end = std::remove_if(c.begin(), c.end(), predicate);
        c.resize(std::distance(c.begin(), end));
    }

    template <class Collection, class T>
    auto Find(Collection& c, const T& value) {
        return std::find(c.begin(), c.end(), value);
    }

    template <class Collection, class Pred>
    auto FindIf(Collection& c, Pred&& predicate) {
        return std::find_if(c.begin(), c.end(), predicate);
    }

    template <class Collection, class T>
    bool Contains(const Collection& c, const T& value) {
        return std::find(c.begin(), c.end(), value) != c.end();
    }

    template <class Collection, class Pred>
    bool ContainsIf(const Collection& c, Pred&& predicate) {
        return std::find_if(c.begin(), c.end(), predicate) != c.end();
    }

    template <class Collection, class Pred>
    int CountIf(const Collection& c, Pred&& predicate) {
        return std::count_if(c.begin(), c.end(), predicate);
    }

    template <class T>
    const T* minPointer(const T* v1, const T* v2) {
        if (*v1 > *v2)
            return v2;
        return v1;
    }

    template <class T>
    const auto& Min(const T& v) {
        return v;
    }

    template <class T, class...Args>
    const auto& Min(const T& arg, const Args&... args) {
        const auto& point = Min(args...);

        if (arg < point)
            return arg;
        return point;
    }

    template <class T>
    const auto& Max(const T& v) {
        return v;
    }

    template <class T, class...Args>
    const auto& Max(const T& arg, const Args&... args) {
        const auto& point = Max(args...);

        if (arg > point)
            return arg;
        return point;
    }

    template <class Collection>
    auto MaxElement(const Collection& c) {
        auto end = c.end();
        auto maxIt = c.begin();

        for (auto beg = c.begin(); beg != end; beg++)
            if (*maxIt < *beg)
                maxIt = beg;
        return maxIt;
    }

    template <class Collection>
    auto MinElement(const Collection& c) {
        auto end = c.end();
        auto minIt = c.begin();

        for (auto beg = c.begin(); beg != end; beg++)
            if (*minIt > *beg)
                minIt = beg;
        return minIt;
    }

    template <class Collection, class Comp>
    auto MaxElement(const Collection& c, Comp&& comparator) {
        auto end = c.end();
        auto maxIt = c.begin();

        for (auto beg = c.begin(); beg != end; beg++)
            if (comparator(*beg, *maxIt))
                maxIt = beg;
        return maxIt;
    }

    template <class Collection, class Comp>
    auto MinElement(const Collection& c, Comp&& comparator) {
        auto end = c.end();
        auto minIt = c.begin();

        for (auto beg = c.begin(); beg != end; beg++)
            if (comparator(*minIt, *beg))
                minIt = beg;
        return minIt;
    }

    template <class Collection>
    void Sort(Collection& c) {
        sort(c.begin(), c.end());
    }

    template <class Collection, class Comp>
    void Sort(Collection& c, Comp&& comparator) {
        for (auto it1 = c.begin(); it1 != c.end(); it1++) {
            auto it2 = it1;
            auto endIt = std::remove_if(++it2, c.end(),
                                        [it1] (auto str)
                                        {return str == *it1;});
            int size = std::distance(c.begin(), endIt);

            c.resize(size);
        }
    }

    template <class Collection>
    void Unique(Collection& c) {
        for (auto it1 = c.begin(); it1 != c.end(); it1++) {
            auto it2 = it1;
            auto endIt = std::remove_if(++it2, c.end(),
                                        [it1] (auto str)
                                        {return str == *it1;});
            int size = std::distance(c.begin(), endIt);

            c.resize(size);
        }
    }

    template <class Collection, class Pred>
    void Unique(Collection& c, Pred&& predicate) {
        for (auto it1 = c.begin(); it1 != c.end(); it1++) {
            auto it2 = it1;
            auto endIt = std::remove_if(++it2, c.end(),
                                        [it1, predicate] (auto el)
                                        {return predicate(*it1, el);});
            int size = std::distance(c.begin(), endIt);

            c.resize(size);
        }
    }

    template <class Collection, class Pred>
    void ForEach(Collection& c, Pred&& predicate) {
        for (auto& el : c)
            predicate(el);
    }

    template <class Collection, class T>
    int IndexOf(const Collection& c, const T& value) {
        int i = -1;

        for (auto it = c.begin(); it != c.end(); it++) {
            i++;
            if (*it == value)
                return i;
        }
        return -1;
    }

    template <class Collection, class Pred>
    int IndexOfIf(const Collection& c, Pred&& predicate) {
        int i = -1;

        for (auto it = c.begin(); it != c.end(); it++) {
            i++;
            if (predicate(*it))
                return i;
        }
        return -1;
    }
}
