#pragma once

#include <memory>
#include <vector>

namespace structures
{

template <typename ValueType>
using Row = std::vector<ValueType>;

template <typename ValueType>
using RowSPtr = std::shared_ptr<Row<ValueType>>;

template <typename ValueType>
class CSVContainer
{
public:
    void append(RowSPtr<ValueType> row);

    std::size_t rowCount() const noexcept;
    std::size_t columnCount() const noexcept;

    typename std::vector<RowSPtr<ValueType>>::iterator begin();
    typename std::vector<RowSPtr<ValueType>>::iterator end();

    typename std::vector<RowSPtr<ValueType>>::const_iterator cbegin();
    typename std::vector<RowSPtr<ValueType>>::const_iterator cend();

private:
    std::vector<RowSPtr<ValueType>> m_data;
};

template <typename ValueType>
void CSVContainer<ValueType>::append(RowSPtr<ValueType> row)
{
    m_data.push_back(row);
}

template <typename ValueType>
std::size_t CSVContainer<ValueType>::rowCount() const noexcept
{
    return m_data.size();
}

template <typename ValueType>
std::size_t CSVContainer<ValueType>::columnCount() const noexcept
{
    if (rowCount() >= 1)
    {
        return m_data[0]->size();
    }

    return 0;
}

/*
 * Members
 */
template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::iterator CSVContainer<ValueType>::begin()
{
    return m_data.begin();
}

template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::iterator CSVContainer<ValueType>::end()
{
    return m_data.end();
}

template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::const_iterator CSVContainer<ValueType>::cbegin()
{
    return m_data.cbegin();
}

template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::const_iterator CSVContainer<ValueType>::cend()
{
    return m_data.cend();
}

/*
 * Free functions.
 */
template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::iterator begin(CSVContainer<ValueType>& c)
{
    return c.begin();
}

template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::iterator end(CSVContainer<ValueType>& c)
{
    return c.end();
}

template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::const_iterator cbegin(CSVContainer<ValueType>& c)
{
    return c.cbegin();
}

template <typename ValueType>
typename std::vector<RowSPtr<ValueType>>::const_iterator cend(CSVContainer<ValueType>& c)
{
    return c.cend();
}

template <typename ValueType>
using CSVContainerSPtr = std::shared_ptr<CSVContainer<ValueType>>;

} // namespace structures
