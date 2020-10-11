#ifndef SUMOFARGUMENTS_H
#define SUMOFARGUMENTS_H

template<class T, class ...Ts>
T sumOfArguments(T t, Ts... args) {
    return (t + (args + ...));
}

#endif
