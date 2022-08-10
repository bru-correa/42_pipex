# Pipex

This project delves deeper into the concepts of: **Redirection** and **Pipes**.
And also introduces the concept of **Multi-Threading**.

## What is pipex

Pipex is a project at [42](https://www.42sp.org.br/) that require us to
replicate the behavior of the **|** operator in Bash. In order to achieve this,
we must use the `exec` family of functions, use the `dup` family of functions
and learn about forking and waiting on child processes.

## How to build

```bash
# Clone this repository and access the folder
git clone https://github.com/bru-correa/42_pipex.git && cd 42_pipex
# Compile the project with `make`
make
# Done!
```

## How to run

Create a file to use as input, then run `pipex` passing the following arguments:

`./pipex input_file "cmd1 -flags" "cmd2 -flags" ... "cmdN -flags" output_file`

If you want to use here_doc, you must run `pipex` passing the following
arguments:

`./pipex "here_doc" "DELIMITER" "cmd1 -flags" "cmd2 -flags" ... "cmdN -flags"
output_file`

You can pipe as many commands as you like, as long as they are in the PATH
environment variable.

### Comparison between pipex and bash

<table>
  <thead>
    <tr>
      <th colspan=3><h4>Examples</h4></th>
    </tr>
      <th>Using</th>
      <th>Commands</th>
  </thead>
  <tbody>
    <tr>
      <td align="center">pipex</td>
      <td><code>
        ./pipex input_file "cat" "grep a" "wc -c" output_file
      </code></td>
    </tr>
    <tr>
      <td align="center">shell</td>
      <td><code>
        < input_file cat | grep a | wc -c > output_file
      </td></code>
    </tr>
    <tr>
      <td><br></td>
      <td><br></td>
    </tr>
    <tr>
      <td align="center">pipex</td>
      <td><code>
        ./pipex "here_doc" "END" "grep hello" "tr '\n' '. '" output_file
      </code></td>
    </tr>
    <tr>
      <td align="center">shell</td>
      <td><code>
        << END grep hello | tr '\n' '. ' >> output_file
      </td></code>
    </tr>
  </tbody>
</table>
