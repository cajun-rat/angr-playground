import angr
import monkeyhex
import claripy


proj = angr.Project('./test')

initial_state = proj.factory.entry_state(args=["./test"],
                                         remove_options={angr.options.LAZY_SOLVES})

local_assert = proj.loader.find_symbol('local_assert')

simgr = proj.factory.simulation_manager(initial_state)

simgr.explore(find=local_assert.rebased_addr)