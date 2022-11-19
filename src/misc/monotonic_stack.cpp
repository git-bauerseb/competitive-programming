#include <iostream>
#include <vector>

template<typename L>
class MonotonicStack {
    public:
        MonotonicStack(L& compOperator) : m_op{compOperator} {}

        void build_stack(std::vector<int> values);

        const std::vector<int>& get_members() {return m_members;}

    private:
        std::vector<int> m_members;
        L m_op;
};

template<typename L>
void MonotonicStack<L>::build_stack(std::vector<int> values) {
    std::vector<int> stack;

    for (int i = 0; i < values.size(); i++) {
        while (stack.size() > 0 && m_op(stack[stack.size()-1], values[i])) {
            stack.pop_back();
        }

        if (stack.size() > 0) {

        }

        stack.push_back(values[i]);
    }

    m_members = std::move(stack);
}


void nextGreaterIndex(std::vector<int> nums) {

    std::vector<int> stack;
    std::vector<int> next_greater(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {

        int s_top_idx = stack.size() - 1;

        while (stack.size() > 0 && nums[stack[s_top_idx]] < nums[i]) {
            int top = stack[s_top_idx];
            stack.pop_back();

            next_greater[top] = i;
            s_top_idx--;
        }

        stack.push_back(i);
    }


    for (auto& e : next_greater) {
        std::cout << e << " ";
    }

    std::cout << "\n";
}

void nextGreater(std::vector<int> nums) {
    const int n = nums.size();
    std::vector<int> stack;
    std::vector<int> n_greater;

    for (int i = 0; i < n; i++) {
        while (stack.size() > 0 && stack[stack.size() - 1] >= nums[i]) {
            stack.pop_back();
        }

        stack.push_back(nums[i]);
    }

    for (auto& e : stack) {
        std::cout << e << " ";
    }

    std::cout << "\n";
}

int main() {

    /*
    auto compareOp = [&](int& a, int& b) {return a > b;};
    MonotonicStack<decltype(compareOp)> stack{compareOp};

    stack.build_stack({5,3,8,12,1});

    for (const auto& e : stack.get_members()) {
        std::cout << e << " ";
    }

    std::cout << "\n";
    */

    // nextGreaterIndex({13,8,1,5,2,5,9,7,6,12});
    nextGreater({0,1,0,3,2,3});

    return 0;
}