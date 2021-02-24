#pragma once

#include <stack>

namespace core {

template <typename T>
class Stack {
public:
    /// Constructs the stack.
    Stack() = default;

    /// Destructor.
    ~Stack() noexcept = default;

    /// Copy constructor.
    Stack(Stack const& other) = delete;
    /// Copy assignment.
    auto operator=(Stack const& other) -> Stack& = delete;

    /// Move constructor.
    Stack(Stack&& other) noexcept = delete;
    /// Move assignment.
    auto operator=(Stack&& other) noexcept -> Stack& = delete;

    /// Inserts element at the top.
    ///
    /// \param new_top The value of the element to push.
    auto push(T const& new_top) -> void {
        m_stack.push(new_top);
    }

    /// Removes the top element.
    auto pop() -> void {
        m_stack.pop();
    }

    /// Accesses the top element.
    ///
    /// \returns The top element in the stack.
    [[nodiscard]] auto top() const -> T {
        return m_stack.top();
    }

    /// Get the number of elements in the stack.
    ///
    /// \returns The number of elements in the underlying container.
    [[nodiscard]] auto depth() const -> std::size_t {
        return m_stack.size();
    }

private:
    std::stack<T> m_stack;
};
} // namespace core
