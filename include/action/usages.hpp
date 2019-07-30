#ifndef INCLUDED_USAGE_HPP
#define INCLUDED_USAGE_HPP

template <typename T>
class UsageTag {};
class ConsumeTag : UsageTag<ConsumeTag> {};
class PutTag : UsageTag<PutTag> {};

#endif  // INCLUDED_USAGE_HPP
