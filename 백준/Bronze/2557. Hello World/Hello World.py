source_code = 'print("Hello World!")'
bytecode = compile(source_code, 'filename', 'exec')
exec(bytecode)
