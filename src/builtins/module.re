#
# module.re: Methods of the Module builtin
# Copyright (C)2010 Tony Arcieri
# 
# Redistribution is permitted under the MIT license.  See LICENSE for details.
#

module Module
  def call(self, :to_s, args, block)
    (:reia_module, name) = self
    case erl.code.ensure_loaded(name)
    when (:module, name)
      name.to_string()
    when _
      # FIXME: no throw keyword :(
      #throw (:error, (name, "not loaded"))
      :error
    end
  end
  
  def call(self, :inspect, args, block)
    self.to_s()
  end

  def call(self, method, args, block)
    (:reia_module, name) = self
    erl.apply(name, method, [args, block])
  end
end