// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interface:srv/FindClosestWall.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACE__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_HPP_
#define MY_INTERFACE__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interface__srv__FindClosestWall_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_interface__srv__FindClosestWall_Request __declspec(deprecated)
#endif

namespace my_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindClosestWall_Request_
{
  using Type = FindClosestWall_Request_<ContainerAllocator>;

  explicit FindClosestWall_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit FindClosestWall_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    my_interface::srv::FindClosestWall_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interface::srv::FindClosestWall_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FindClosestWall_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FindClosestWall_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interface__srv__FindClosestWall_Request
    std::shared_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interface__srv__FindClosestWall_Request
    std::shared_ptr<my_interface::srv::FindClosestWall_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindClosestWall_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindClosestWall_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindClosestWall_Request_

// alias to use template instance with default allocator
using FindClosestWall_Request =
  my_interface::srv::FindClosestWall_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_interface


#ifndef _WIN32
# define DEPRECATED__my_interface__srv__FindClosestWall_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_interface__srv__FindClosestWall_Response __declspec(deprecated)
#endif

namespace my_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindClosestWall_Response_
{
  using Type = FindClosestWall_Response_<ContainerAllocator>;

  explicit FindClosestWall_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit FindClosestWall_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interface::srv::FindClosestWall_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interface::srv::FindClosestWall_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FindClosestWall_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interface::srv::FindClosestWall_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interface__srv__FindClosestWall_Response
    std::shared_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interface__srv__FindClosestWall_Response
    std::shared_ptr<my_interface::srv::FindClosestWall_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindClosestWall_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindClosestWall_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindClosestWall_Response_

// alias to use template instance with default allocator
using FindClosestWall_Response =
  my_interface::srv::FindClosestWall_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_interface

namespace my_interface
{

namespace srv
{

struct FindClosestWall
{
  using Request = my_interface::srv::FindClosestWall_Request;
  using Response = my_interface::srv::FindClosestWall_Response;
};

}  // namespace srv

}  // namespace my_interface

#endif  // MY_INTERFACE__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_HPP_
