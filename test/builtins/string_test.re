#
# StringTest: Tests for Reia's string type
# Copyright (C)2009-10 Tony Arcieri
# 
# Redistribution is permitted under the MIT license.  See LICENSE for details.
#

module StringTest
  def run
    [
      length_test(),
      to_s_test(),
      inspect_test(), 
      #sub_test(),
      interpolation_test(),
      #split_test(), -- requires Erlang R12B-5, which isn't generally available :/
      to_module_test(),
      to_binary_test(),
      to_list_test(),
      to_atom_test(),
      capitalize_test()
    ]
  end
  
  def length_test
    TestHelper.expect(String, "knows its length") do
      (6, "foobar".length())
    end
  end
  
  def to_s_test
    TestHelper.expect(String, "casts to a string") do
      ("foobar", "foobar".to_s())
    end
  end
        
  def inspect_test
    TestHelper.expect(String, "inspects properly") do
      ("\"foobar\"", "foobar".inspect())
    end
  end
    
  #def sub_test
  #  TestHelper.expect(String, "substitutes properly") do
  #    ("bazbar", "foobar".sub(/foo/, "baz"))
  #  end
  #end
    
  def interpolation_test
    (foo, bar) = (1, 2)
    TestHelper.expect(String, "interpolates nested Reia syntax") do
      ("foo: 1, bar: 2", "foo: #{foo}, bar: #{bar}")
    end
  end
    
  #def split_test
  #  TestHelper.expect(String, "splits properly") do
  #    (["foo", "bar", "baz"], "foo    bar baz".split(/\s+/))
  #  end
  #end
  
  def to_module_test
    TestHelper.expect(String, "converts to a module") do
      (String, "String".to_module())
    end
  end
  
  def to_binary_test
    TestHelper.expect(String, "converts to a binary") do
      (<["foobar"]>, "foobar".to_binary())
    end
  end
  
  def to_list_test
    TestHelper.expect(String, "converts to a list") do
      ([115,117,114,112,114,105,115,101], "surprise".to_list())
    end
  end
  
  def to_atom_test
    TestHelper.expect(String, "converts to a binary") do
      (:foobar, "foobar".to_atom())
    end
  end
  
  def capitalize_test
    TestHelper.expect(String, "capitalizes") do
      ("CamelCase", "camelCase".capitalize())
    end   
  end 
end