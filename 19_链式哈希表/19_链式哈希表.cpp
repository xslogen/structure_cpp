// 19_链式哈希表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


//链式哈希表
class HashTable
{
public:
	HashTable(int size = primes_[0], double loadFactor = 0.75)
		:useBucketNum_(0)
		, loadFactor_(loadFactor)
		, primeIdx_(0)
	{
		if (size != primes_[0])
		{
			for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
			{
				if (primes_[primeIdx_] >= size)
					break;
			}

			if (primeIdx_ == PRIME_SIZE)
			{
				primeIdx_--;
			}
		}

		table_.resize(primes_[primeIdx_]);
	}
public:
	void insert(int key)
	{
		double factor = useBucketNum_ * 1.0 / table_.size();
		std::cout << "factor:" << factor << std::endl;
		if (factor > loadFactor_) {
			expand();
		}
		int idx = key % table_.size();
		if (table_[idx].empty())
		{
			useBucketNum_++;
			table_[idx].emplace_front(key);
		}
		else
		{
			auto it = std::find(table_[idx].begin(), table_[idx].end(), key);
			if (it == table_[idx].end())
			{
				//key 不存在，插入
				table_[idx].emplace_front(key);
			}
		}
	}
	void erase(int key)
	{
		int idx = key % table_.size();
		auto it = std::find(table_[idx].begin(), table_[idx].end(), key);
		if (it != table_[idx].end())
		{
			table_[idx].erase(it);
			if (table_[idx].empty())
			{
				useBucketNum_--;
			}
		}
	}
	bool find(int key)
	{
		int idx = key % table_.size();
		auto it = std::find(table_[idx].begin(), table_[idx].end(), key);
		return it != table_[idx].end();
	}
private:
	void expand()
	{
		if (primeIdx_ + 1 == PRIME_SIZE)
		{
			throw "hashtable can not expand any more";
		}
		primeIdx_++;
		useBucketNum_ = 0;
		std::vector<std::list<int>> oldTable;
		table_.swap(oldTable);
		table_.resize(primes_[primeIdx_]);
		for (auto list : oldTable)
		{
			for (auto key : list)
			{
				int idx = key % table_.size();
				if (table_[idx].empty())
				{
					useBucketNum_++;
				}
				table_[idx].emplace_front(key);
			}
		}
	}

private:
	std::vector<std::list<int>> table_; //存储数据
	int useBucketNum_; //已使用的桶数
	double loadFactor_; //装载因子
	static const int PRIME_SIZE = 10; //质数表大小
	static int primes_[PRIME_SIZE]; //质数表
	int  primeIdx_;//当前使用的素数下标
};
int HashTable::primes_[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };
int main()
{
	HashTable htable;
	htable.insert(21);
	htable.insert(32);
	htable.insert(14);
	htable.insert(15);

	htable.insert(22);

	htable.insert(67);

	cout << htable.find(67) << endl;
	htable.erase(67);
	cout << htable.find(67) << endl;

	return 0;
}