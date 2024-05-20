# [Diamond V] Interpreter - 11516 

[문제 링크](https://www.acmicpc.net/problem/11516) 

### 성능 요약

메모리: 34952 KB, 시간: 132 ms

### 분류

구현, 파싱, 문자열

### 제출 일자

2024년 5월 20일 15:20:15

### 문제 설명

<p>Wouldn't it be cool if your favorite language had feature XYZ? Well, your professor has started you on your journey to design your own language with your own features. Perhaps you'll even find time to include blackjack, among other things, in the language. Until then, your first class assignment is to write an interpreter for a simple programming language.</p>

<h3>Data Types</h3>

<p>The language has a single data type, a 32-bit signed integer.</p>

<p>Operators and statements that generally operate on booleans (<code>!</code>, <code>&&</code>, <code>||</code>, <code>if</code>, and <code>while</code>) treat <code>0</code> (zero) as false and all other values as true.</p>

<p>Operators that generally result in a boolean (<code>!</code>, <code><</code>, <code><=</code>, <code>></code>, <code>>=</code>, <code>==</code>, <code>!=</code>, <code>&&</code>, and <code>||</code>) return <code>0</code> (zero) for false and <code>1</code> (one) for true.</p>

<h3>Variables</h3>

<p>Each variable name is a single lowercase letter between 'a' and 'z'. All variables are implicitly initialized to <code>0</code> (zero) at the beginning of each program.</p>

<h3>Whitespace</h3>

<p>Each simple statement (<code>set</code> or <code>print</code>) or part of a compound statement (<code>if</code>, <code>else</code>, <code>end if</code>, <code>while</code>, <code>end while</code>) is on its own line.</p>

<p>There are no blank lines.</p>

<p>Any amount of whitespace (space or tab) may occur before or after any token (operator, variable name, keyword, constant, etc.). It will not occur within a token. It is only guaranteed to be present between 2 alphanumeric tokens.</p>

<h3>Statements</h3>

<p>A statement consists of any of the following:</p>

<h3>If (with else):</h3>

<pre>if expression
    statements
else
    statements
end if</pre>

<p>Run the zero or more statements in the first block if <code>expression</code> evaluates to true (non-zero). Otherwise, run the zero or more statements in the second block.</p>

<h3>If (without else):</h3>

<pre>if expression
    statements
end if</pre>

<p>Run the zero or more statements in the block if <code>expression</code> evaluates to true (non-zero). Otherwise, skip the block.</p>

<h3>While:</h3>

<pre>while expression
    statements
end while</pre>

<p>Evaluate <code>expression</code>. If it is true (non-zero), run the zero or more statements in the block and return to the start of the <code>while</code> statement to re-evaluate the expression. Otherwise, skip the block.</p>

<h3>Assignment:</h3>

<pre>set name = expression</pre>

<p>Set the variable named name to the result of <code>expression</code>.</p>

<h3>Output:</h3>

<pre>print expression</pre>

<p>Write the result of <code>expression</code> to stdout on its own line.</p>

<h3>Expressions</h3>

<p>An expression consists of a variable name, integer value (sequence of digits with a value between 0 and 2<sup>31</sup>-1 inclusive), or any of the operations listed below.</p>

<p>Some operators have a higher precedence than others; <code>1+2*3</code> is equivalent to <code>1+(2*3)</code>, though <code>1*2+3</code> is equivalent to <code>(1*2)+3</code>.</p>

<p>Within a single precedence level, binary operators group left-to-right, and unary operators group right-to-left. For example, <code>1+2-3</code> is equivalent to <code>(1+2)-3</code>, and <code>!-x</code> is equivalent to <code>!(-x)</code>.</p>

<table class="table table-bordered" style="width:50%">
	<thead>
		<tr>
			<th>Precedence</th>
			<th>Operator</th>
			<th>Description</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>7</td>
			<td><code>()</code></td>
			<td>grouping</td>
		</tr>
		<tr>
			<td rowspan="2">6</td>
			<td><code>-</code></td>
			<td>unary minus (additive inverse)</td>
		</tr>
		<tr>
			<td><code>!</code></td>
			<td>logical negation (not)</td>
		</tr>
		<tr>
			<td rowspan="3">5</td>
			<td><code>*</code></td>
			<td>multiplication</td>
		</tr>
		<tr>
			<td><code>/</code></td>
			<td>integer division</td>
		</tr>
		<tr>
			<td><code>%</code></td>
			<td>modulo (remainder)</td>
		</tr>
		<tr>
			<td rowspan="2">4</td>
			<td><code>+</code></td>
			<td>addition</td>
		</tr>
		<tr>
			<td><code>-</code></td>
			<td>subtraction</td>
		</tr>
		<tr>
			<td rowspan="4">3</td>
			<td><code><</code></td>
			<td>less than</td>
		</tr>
		<tr>
			<td><code><=</code></td>
			<td>less than or equal</td>
		</tr>
		<tr>
			<td><code>></code></td>
			<td>greater than</td>
		</tr>
		<tr>
			<td><code>>=</code></td>
			<td>greater than or equal</td>
		</tr>
		<tr>
			<td rowspan="2">2</td>
			<td><code>==</code></td>
			<td>equal</td>
		</tr>
		<tr>
			<td><code>!=</code></td>
			<td>not equal</td>
		</tr>
		<tr>
			<td>1</td>
			<td><code>&&</code></td>
			<td>logical and</td>
		</tr>
		<tr>
			<td>0</td>
			<td><code>||</code></td>
			<td>logical or</td>
		</tr>
	</tbody>
</table>

<p>All final and intermediate values will fit in a 32-bit signed integer; no overflow detection is necessary.</p>

<p>Division (both <code>/</code> and <code>%</code>) by 0 will not occur.</p>

### 입력 

 <p>Input consists of 1 or more programs. Each begins with a line containing the number of lines (N, 1 <= N <= 50) in that program. The following N lines contain the program to run. No line is longer than 100 characters. Input is terminated when N equals 0 (zero).</p>

### 출력 

 <p>Output consists only of the result of the <code>print</code> statements in the programs as described above.</p>

