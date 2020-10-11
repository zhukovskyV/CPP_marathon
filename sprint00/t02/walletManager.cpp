#include "walletManager.h"

Wallet* createWallet(int n) {
   Wallet* wallet = new Wallet;
   wallet->septims = n;

   return wallet;
}

void destroyWallet(Wallet* wallet) {
    delete wallet;
}

Wallet* createWallets(int n) {
    Wallet* wallet = new Wallet[n];

    return wallet;
}

void destroyWallets(Wallet* wallet) {
    delete[] wallet;
}
