#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

bool Writer::is_closed() const
{
  // Your code here.
  return is_closed_;
}

void Writer::push( string data )
{
  // Your code here.
  if (has_error() or is_closed_ or data.empty()) {
    return;
  }

  uint64_t length = min(data.length(), available_capacity());
  buffer += data.substr(0, length);
  total_number_in += length;
  return;
}

void Writer::close()
{
  // Your code here.
  is_closed_ = true;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - buffer.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return this->total_number_in;
}

bool Reader::is_finished() const
{
  // Your code here.
  return buffer.empty() && is_closed_;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return this->total_number_out;
}

string_view Reader::peek() const
{
  // Your code here.
  return std::string_view(buffer.c_str(), 1);
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if (len == 0) {
    return;
  }
  if (!has_error()) {
    uint64_t length = min(len, bytes_buffered());
    buffer.erase(0, length);
    total_number_out += length;
  }
  return;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return this->buffer.size();
}
