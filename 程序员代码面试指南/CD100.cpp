/*
 * @Author: m1ng
 * @Date: 2021-07-22 00:40:42
 * @LastEditors: m1ng
 * @LastEditTime: 2021-07-24 00:25:56
 * @FilePath: \leetcode_test\程序员代码面试指南\CD100.cpp
 * @Description: header
 */
#include<queue>
#include<string>
using namespace std;
class Pet
{
private:
    string type;
public:
    Pet(string type){
        this->type=type;
    }
    string getpetType(){
        return this->type;
    }
};
static Pet cat("cat");
static Pet dog("dog");

class petEnterQueue
{
public:
    Pet pet;
    long count;
    petEnterQueue(Pet pet,long count){
        this->pet=pet;
        this->count = count;
    }
    Pet getpet(){
        return this->pet;
    }
    long getcount(){
        return this->count;
    }
    string getEnterPetType(){
        return this->pet.getpetType();
    }
};

class Soulution
{
public:
    queue<petEnterQueue> catQ;
    queue<petEnterQueue> dogQ;
    long count;
    Soulution();
    void add(Pet pet){
        if(pet.getpetType()=="dog")
        {
            ;
        }
    }
};

Soulution::Soulution(queue<petEnterQueue> catQ,
    queue<petEnterQueue> dogQ;)
{
    this->catQ=catQ;
    this->dogQ=dogQ;
    this->count = 0;
}
