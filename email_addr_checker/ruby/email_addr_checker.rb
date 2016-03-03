#!/usr/bin/ruby

require 'test/unit'

def is_email_addr_valid?(addr)
  email_pattern = /^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$/
  email_pattern.match(addr) != nil
end

class TC_EmailAddrCheckerTest < Test::Unit::TestCase
  def test_simple_addr
    assert(is_email_addr_valid?('user@example.com'))
  end

  def test_addr_without_separator
    assert(!is_email_addr_valid?('user.example.com'))
  end

end


