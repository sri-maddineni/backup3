package com.itkonnects.wholesalefoodtrial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.itkonnects.wholesalefoodtrial.ui.theme.WholeSaleFoodTrialTheme
import androidx.compose.foundation.BorderStroke
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.ui.draw.shadow

class CalculatorActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            WholeSaleFoodTrialTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    CalculatorScreen(modifier = Modifier.padding(innerPadding))
                }
            }
        }
    }
}

@Composable
fun CalculatorScreen(modifier: Modifier = Modifier) {
    var input by remember { mutableStateOf("") }
    var result by remember { mutableStateOf("") }

    // Live preview logic
    fun updatePreview() {
        if (input.isBlank()) {
            result = ""
            return
        }
        try {
            result = eval(input).toString()
        } catch (e: Exception) {
            result = ""
        }
    }

    fun onButtonClick(value: String) {
        when (value) {
            "C" -> {
                input = ""
                result = ""
            }
            "=" -> {
                try {
                    result = eval(input).toString()
                } catch (e: Exception) {
                    result = "Error"
                }
            }
            else -> {
                input += value
                updatePreview()
            }
        }
    }

    Box(
        modifier = modifier.fillMaxSize(),
        contentAlignment = Alignment.Center
    ) {
        Card(
            modifier = Modifier
                .padding(16.dp)
                .shadow(8.dp, RoundedCornerShape(24.dp)),
            shape = RoundedCornerShape(24.dp),
            colors = CardDefaults.cardColors(
                containerColor = MaterialTheme.colorScheme.surface,
                contentColor = MaterialTheme.colorScheme.onSurface
            ),
            elevation = CardDefaults.cardElevation(8.dp)
        ) {
            Column(
                modifier = Modifier.padding(24.dp),
                verticalArrangement = Arrangement.Top,
                horizontalAlignment = Alignment.CenterHorizontally
            ) {
                Text(
                    text = input,
                    fontSize = 32.sp,
                    modifier = Modifier
                        .fillMaxWidth()
                        .padding(8.dp),
                    fontWeight = FontWeight.Bold,
                    color = MaterialTheme.colorScheme.primary
                )
                Text(
                    text = result,
                    fontSize = 24.sp,
                    modifier = Modifier
                        .fillMaxWidth()
                        .padding(8.dp),
                    color = if (result == "Error") MaterialTheme.colorScheme.error else MaterialTheme.colorScheme.secondary
                )
                Spacer(modifier = Modifier.height(16.dp))
                val buttons = listOf(
                    listOf("7", "8", "9", "/"),
                    listOf("4", "5", "6", "*"),
                    listOf("1", "2", "3", "-"),
                    listOf("0", ".", "C", "+"),
                    listOf("=")
                )
                for (row in buttons) {
                    Row(
                        modifier = Modifier.fillMaxWidth(),
                        horizontalArrangement = Arrangement.SpaceEvenly
                    ) {
                        for (button in row) {
                            Button(
                                onClick = { onButtonClick(button) },
                                modifier = Modifier
                                    .weight(1f)
                                    .padding(4.dp),
                                shape = RoundedCornerShape(12.dp),
                                border = BorderStroke(1.dp, MaterialTheme.colorScheme.primary),
                                colors = ButtonDefaults.buttonColors(
                                    containerColor = if (button in listOf("=", "C")) MaterialTheme.colorScheme.primary else MaterialTheme.colorScheme.background,
                                    contentColor = if (button in listOf("=", "C")) MaterialTheme.colorScheme.onPrimary else MaterialTheme.colorScheme.primary
                                )
                            ) {
                                Text(button, fontSize = 24.sp, fontWeight = FontWeight.Medium)
                            }
                        }
                    }
                }
            }
        }
    }
}

// Simple expression evaluator for +, -, *, /
fun eval(expr: String): Double {
    return object : Any() {
        var pos = -1
        var ch = 0
        fun nextChar() { ch = if (++pos < expr.length) expr[pos].toInt() else -1 }
        fun eat(charToEat: Int): Boolean {
            while (ch == ' '.toInt()) nextChar()
            if (ch == charToEat) { nextChar(); return true }
            return false
        }
        fun parse(): Double {
            nextChar()
            val x = parseExpression()
            if (pos < expr.length) throw RuntimeException("Unexpected: " + expr[pos])
            return x
        }
        fun parseExpression(): Double {
            var x = parseTerm()
            while(true) {
                when {
                    eat('+'.toInt()) -> x += parseTerm()
                    eat('-'.toInt()) -> x -= parseTerm()
                    else -> return x
                }
            }
        }
        fun parseTerm(): Double {
            var x = parseFactor()
            while(true) {
                when {
                    eat('*'.toInt()) -> x *= parseFactor()
                    eat('/'.toInt()) -> x /= parseFactor()
                    else -> return x
                }
            }
        }
        fun parseFactor(): Double {
            if (eat('+'.toInt())) return parseFactor()
            if (eat('-'.toInt())) return -parseFactor()
            var x: Double
            val startPos = pos
            if (eat('('.toInt())) {
                x = parseExpression()
                eat(')'.toInt())
            } else if ((ch >= '0'.toInt() && ch <= '9'.toInt()) || ch == '.'.toInt()) {
                while ((ch >= '0'.toInt() && ch <= '9'.toInt()) || ch == '.'.toInt()) nextChar()
                x = expr.substring(startPos, pos).toDouble()
            } else {
                throw RuntimeException("Unexpected: " + ch.toChar())
            }
            return x
        }
    }.parse()
} 