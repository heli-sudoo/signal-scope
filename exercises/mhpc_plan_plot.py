
# This reads every .py file in the given directory and catalogs
# everything that is an lcm type python definition file.
findLCMTypes(os.path.expanduser('lcm-types/python'))


# This looks for lcm packages.  An lcm package is a directory
# that contains an __init__.py file and lcm type python files.
findLCMModules(os.path.expanduser('lcm-types/python'))

p = addPlot()

addSignalSequence("MPCPlan", msg.timestep, msg.pos, plot = p)