
# This reads every .py file in the given directory and catalogs
# everything that is an lcm type python definition file.


findLCMTypes(os.path.expanduser('lcm-types/python'))


# This looks for lcm packages.  An lcm package is a directory
# that contains an __init__.py file and lcm type python files.
findLCMModules(os.path.expanduser('lcm-types/python'))

# Plot one sequence
p = addPlot()
addSignalSequence("MPCPlan", msg.timestep, msg.pos[0], plot = p)

# Plot multiple sequences
import colorsys
keys = [0, 1, 2]
N = len(keys)
HSV_tuples = [(x*1.0/N, 1.0, 1.0) for x in range(N)]
RGB_tuples = map(lambda x: colorsys.hsv_to_rgb(*x), HSV_tuples)

pm = addPlot()
addSignalSequences("MPCPlan", msg.timestep, msg.pos, [0, 1, 2], plot = pm)
setFormatOptions(curveStyle='lines')