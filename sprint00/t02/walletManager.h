#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <iostream>

struct Wallet{
    int septims;
};

Wallet* createWallet(int n);
void destroyWallet(Wallet *wallet);
Wallet* createWallets(int n);
void destroyWallets(Wallet *Wallet);

#endif

