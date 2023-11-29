# Pymer - The Python Clock Cycle Counter

Uses the `rdtsc` instruction to get the current clock timestamp. Can be used in a pattern similar to `timeit`` or the regular Python `time` module. Note that timestamps will never be 100% accurate if you do not set the process affinity to dedicate an entire core to the script you are timing. [See this link for more info on setting affinity.](https://unix.stackexchange.com/questions/73/how-can-i-set-the-processor-affinity-of-a-process-on-linux)

## Examples
Example usage is contained within `example.py`. Pymer only exports one function, `timestamp` to be used in a Python script, so it's very easy to use:
```
from pymer import timestamp

start = timestamp()

** do whatever **

end = timestamp()

print(end - start)
```

## Build
`python setup.py build`

## Install
From PyPi:
```
pip install pymer-timer
```

From source:
```
git clone https://github.com/joshbarbee/pymer
cd pymer
python setup.py install
```

## Usage

Pymer only exports one function, `timestamp`. It takes no arguments. Any other questions?
