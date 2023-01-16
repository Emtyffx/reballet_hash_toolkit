# Reballet hash toolkit
## Usage


Find hash phrase from word list
```bash
./ReballetHash -q path/to/wordlist -H [HASH] -a [ALGORITHM]
```

Hash every line of one file and save to another

```bash
./ReballetHash -L -q path/to/input -o path/to/output
```

Note: if you want to trim every line, add -t key
