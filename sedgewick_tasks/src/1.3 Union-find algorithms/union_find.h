#pragma once

#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <cstdint>
#include <utility>
#include <functional>

namespace union_find_algorithms
{

class DisjointSet
{
private:
    struct Node
    {
        std::uint64_t value_;
        std::shared_ptr<std::unordered_set<std::uint64_t>> myGroup_ = nullptr;
        Node() = default;
        Node(std::uint64_t value, std::shared_ptr<std::unordered_set<std::uint64_t>> myGroup) :
            value_(value),
            myGroup_(myGroup)
        {
        }
    };
    std::unordered_map<std::uint64_t, Node> nodes_;

public:
    void add(std::uint64_t value1, std::uint64_t value2);
};

}



inline void union_find_algorithms::DisjointSet::add(std::uint64_t value1, std::uint64_t value2)
{
    if (nodes_.count(value1) == 0)
    {
        if (nodes_.count(value2) == 0)
        {
            auto newGroup = std::make_shared<std::unordered_set<std::uint64_t>>();
            newGroup->insert(value1);
            newGroup->insert(value2);

            nodes_.emplace(value1, Node(value1, newGroup));
            nodes_.emplace(value2, Node(value2, newGroup));
        }
        else
        {
            auto& group = nodes_.at(value2).myGroup_;
            group->insert(value1);

            nodes_.emplace(value1, Node(value1, group));
        }
    }
    else
    {
        if (nodes_.count(value2) == 0)
        {
            auto group = nodes_.at(value1).myGroup_;
            group->insert(value2);

            nodes_.emplace(value2, Node(value2, group));
        }
        else
        {
            auto& group1 = nodes_.at(value1).myGroup_;
            auto& group2 = nodes_.at(value2).myGroup_;

            group1->merge(*group2);
            group2 = group1;
        }
    }
}
