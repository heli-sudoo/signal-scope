### Generate LCM types
```
cd scripts
./make_types.sh
```

### Build publisher

```
g++ -o publisher.o publisher.cpp -llcm
```

### Run publisher
```
./publisher seq
```
### Open a new terminal and run signal scope

```
signal-scope mhpc_plan_plot.py
```