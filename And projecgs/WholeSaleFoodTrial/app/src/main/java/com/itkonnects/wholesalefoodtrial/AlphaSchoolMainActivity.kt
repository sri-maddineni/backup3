package com.itkonnects.wholesalefoodtrial

import android.Manifest
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Menu
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.itkonnects.wholesalefoodtrial.ui.theme.WholeSaleFoodTrialTheme
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.content.pm.PackageManager
import android.os.Build
import androidx.compose.ui.platform.LocalContext
import androidx.core.app.ActivityCompat
import androidx.core.app.NotificationCompat
import androidx.core.app.NotificationManagerCompat
import kotlinx.coroutines.launch
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.icons.filled.Info
import androidx.compose.material.icons.filled.Phone
import androidx.compose.material.icons.filled.Email
import androidx.compose.material.icons.filled.Lock
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import androidx.compose.foundation.clickable

sealed class AlphaSchoolScreen(val title: String) {
    object Home : AlphaSchoolScreen("Home")
    object About : AlphaSchoolScreen("About Us")
    object Classes : AlphaSchoolScreen("Classes/Timetable")
    object Teachers : AlphaSchoolScreen("Teachers/Staff")
    object Students : AlphaSchoolScreen("Students")
    object Events : AlphaSchoolScreen("Events/Notices")
    object Gallery : AlphaSchoolScreen("Gallery")
    object Contact : AlphaSchoolScreen("Contact Us")
}

class AlphaSchoolMainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            WholeSaleFoodTrialTheme {
                AlphaSchoolApp()
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun AlphaSchoolApp() {
    val screens = listOf(
        AlphaSchoolScreen.Home,
        AlphaSchoolScreen.About,
        AlphaSchoolScreen.Classes,
        AlphaSchoolScreen.Teachers,
        AlphaSchoolScreen.Students,
        AlphaSchoolScreen.Events,
        AlphaSchoolScreen.Gallery,
        AlphaSchoolScreen.Contact
    )
    var drawerState = rememberDrawerState(DrawerValue.Closed)
    val scope = rememberCoroutineScope()
    var selectedScreen by remember { mutableStateOf<AlphaSchoolScreen>(AlphaSchoolScreen.Home) }

    ModalNavigationDrawer(
        drawerState = drawerState,
        drawerContent = {
            ModalDrawerSheet {
                Column(
                    modifier = Modifier.padding(16.dp),
                    horizontalAlignment = Alignment.CenterHorizontally
                ) {
                    // Placeholder for logo
                    Surface(
                        modifier = Modifier.size(80.dp).clip(CircleShape),
                        color = MaterialTheme.colorScheme.primary
                    ) {}
                    Spacer(modifier = Modifier.height(12.dp))
                    Text("Alpha School", fontWeight = FontWeight.Bold, fontSize = 22.sp)
                    Spacer(modifier = Modifier.height(24.dp))
                }
                screens.forEach { screen ->
                    NavigationDrawerItem(
                        label = { Text(screen.title) },
                        selected = selectedScreen == screen,
                        onClick = {
                            selectedScreen = screen
                            scope.launch { drawerState.close() }
                        },
                        modifier = Modifier.padding(NavigationDrawerItemDefaults.ItemPadding)
                    )
                }
            }
        }
    ) {
        Scaffold(
            topBar = {
                SmallTopAppBar(
                    title = { Text(selectedScreen.title) },
                    navigationIcon = {
                        IconButton(onClick = { scope.launch { drawerState.open() } }) {
                            Icon(Icons.Default.Menu, contentDescription = "Menu")
                        }
                    }
                )
            }
        ) { innerPadding ->
            Box(modifier = Modifier.padding(innerPadding).fillMaxSize()) {
                when (selectedScreen) {
                    is AlphaSchoolScreen.Home -> AlphaSchoolHomeScreen()
                    is AlphaSchoolScreen.About -> AlphaSchoolAboutScreen()
                    is AlphaSchoolScreen.Classes -> AlphaSchoolClassesScreen()
                    is AlphaSchoolScreen.Teachers -> AlphaSchoolTeachersScreen()
                    is AlphaSchoolScreen.Students -> AlphaSchoolStudentsScreen()
                    is AlphaSchoolScreen.Events -> AlphaSchoolEventsScreen()
                    is AlphaSchoolScreen.Gallery -> AlphaSchoolGalleryScreen()
                    is AlphaSchoolScreen.Contact -> AlphaSchoolContactScreen()
                }
            }
        }
    }
}

@Composable
fun AlphaSchoolHomeScreen() {
    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Surface(
            modifier = Modifier.size(120.dp).clip(CircleShape),
            color = MaterialTheme.colorScheme.primary
        ) {}
        Spacer(modifier = Modifier.height(16.dp))
        Text("Welcome to Alpha School!", fontWeight = FontWeight.Bold, fontSize = 26.sp)
        Spacer(modifier = Modifier.height(8.dp))
        Text("Empowering students for a brighter future.", fontSize = 18.sp, color = Color.Gray)
    }
}

// Placeholder composables for other screens
@Composable fun AlphaSchoolAboutScreen() {
    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Icon(Icons.Default.Info, contentDescription = "About", tint = MaterialTheme.colorScheme.primary, modifier = Modifier.size(48.dp))
        Spacer(modifier = Modifier.height(16.dp))
        Card(
            modifier = Modifier.fillMaxWidth(),
            shape = RoundedCornerShape(16.dp),
            elevation = CardDefaults.cardElevation(4.dp)
        ) {
            Column(modifier = Modifier.padding(16.dp)) {
                Text("About Alpha School", fontWeight = FontWeight.Bold, fontSize = 20.sp)
                Spacer(modifier = Modifier.height(8.dp))
                Text("Alpha School is a place of learning and growth. Mission: Excellence. Vision: Success.", color = Color.Gray)
            }
        }
    }
}
@Composable fun AlphaSchoolClassesScreen() {
    val timetable = listOf(
        listOf("Time", "Class 5", "Class 6", "Class 7"),
        listOf("8:00-9:00", "Math", "English", "Science"),
        listOf("9:00-10:00", "Science", "Math", "English"),
        listOf("10:00-11:00", "English", "Science", "Math"),
        listOf("11:00-12:00", "PE", "History", "Art"),
        listOf("12:00-1:00", "Lunch", "Lunch", "Lunch"),
        listOf("1:00-2:00", "History", "PE", "Math")
    )
    Column(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Class Timetable", fontWeight = FontWeight.Bold, fontSize = 22.sp, modifier = Modifier.padding(8.dp))
        timetable.forEachIndexed { rowIndex, row ->
            Row(
                modifier = Modifier.fillMaxWidth(),
                horizontalArrangement = Arrangement.SpaceEvenly
            ) {
                row.forEachIndexed { colIndex, cell ->
                    Surface(
                        modifier = Modifier
                            .weight(1f)
                            .padding(2.dp),
                        color = if (rowIndex == 0) MaterialTheme.colorScheme.primary.copy(alpha = 0.2f) else MaterialTheme.colorScheme.surface,
                        shape = RoundedCornerShape(8.dp)
                    ) {
                        Text(
                            cell,
                            modifier = Modifier.padding(8.dp),
                            textAlign = TextAlign.Center,
                            fontWeight = if (rowIndex == 0) FontWeight.Bold else FontWeight.Normal
                        )
                    }
                }
            }
        }
    }
}
@Composable fun AlphaSchoolTeachersScreen() {
    // Nested navigation for teachers
    val navController = rememberNavController()
    NavHost(navController = navController, startDestination = "teacherList") {
        composable("teacherList") {
            TeacherListScreen(onTeacherClick = { teacher ->
                navController.navigate("teacherDetail/${teacher.name}")
            })
        }
        composable("teacherDetail/{teacherName}") { backStackEntry ->
            val teacherName = backStackEntry.arguments?.getString("teacherName") ?: "Unknown"
            TeacherDetailScreen(teacherName = teacherName, onScheduleClick = {
                navController.navigate("teacherSchedule/$teacherName")
            }, onBack = { navController.popBackStack() })
        }
        composable("teacherSchedule/{teacherName}") { backStackEntry ->
            val teacherName = backStackEntry.arguments?.getString("teacherName") ?: "Unknown"
            TeacherScheduleScreen(
                teacherName = teacherName,
                onBack = { navController.popBackStack() },
                onSlotClick = { slot ->
                    navController.navigate("teacherScheduleSlotDetail/$teacherName/$slot")
                }
            )
        }
        composable("teacherScheduleSlotDetail/{teacherName}/{slot}") { backStackEntry ->
            val teacherName = backStackEntry.arguments?.getString("teacherName") ?: "Unknown"
            val slot = backStackEntry.arguments?.getString("slot") ?: "Unknown Slot"
            TeacherScheduleSlotDetailScreen(teacherName = teacherName, slot = slot, onBack = { navController.popBackStack() })
        }
    }
}

@Composable
fun TeacherListScreen(onTeacherClick: (TeacherProfile) -> Unit) {
    val teachers = listOf(
        TeacherProfile("Mr. Smith", "Mathematics"),
        TeacherProfile("Ms. Johnson", "English"),
        TeacherProfile("Mrs. Lee", "Science"),
        TeacherProfile("Mr. Brown", "History"),
        TeacherProfile("Ms. Green", "Physical Education")
    )
    Column(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Our Teachers", fontWeight = FontWeight.Bold, fontSize = 22.sp, modifier = Modifier.padding(8.dp))
        LazyColumn(modifier = Modifier.fillMaxWidth()) {
            items(teachers) { teacher ->
                ProfileCard(name = teacher.name, subtitle = teacher.subject, onClick = { onTeacherClick(teacher) })
            }
        }
    }
}

@Composable
fun TeacherDetailScreen(teacherName: String, onScheduleClick: () -> Unit, onBack: () -> Unit) {
    // Dummy details
    val teacher = when (teacherName) {
        "Mr. Smith" -> TeacherProfile("Mr. Smith", "Mathematics")
        "Ms. Johnson" -> TeacherProfile("Ms. Johnson", "English")
        "Mrs. Lee" -> TeacherProfile("Mrs. Lee", "Science")
        "Mr. Brown" -> TeacherProfile("Mr. Brown", "History")
        "Ms. Green" -> TeacherProfile("Ms. Green", "Physical Education")
        else -> TeacherProfile(teacherName, "Unknown")
    }
    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        ProfileCard(name = teacher.name, subtitle = teacher.subject)
        Spacer(modifier = Modifier.height(16.dp))
        Text("Bio: ${teacher.name} is an experienced ${teacher.subject} teacher at Alpha School.", color = Color.Gray, textAlign = TextAlign.Center)
        Spacer(modifier = Modifier.height(24.dp))
        Button(onClick = onScheduleClick) {
            Text("View Schedule")
        }
        Spacer(modifier = Modifier.height(16.dp))
        OutlinedButton(onClick = onBack) {
            Text("Back")
        }
    }
}

@Composable
fun TeacherScheduleScreen(teacherName: String, onBack: () -> Unit, onSlotClick: (String) -> Unit) {
    // Dummy schedule
    val schedule = listOf(
        "Monday: 8am-10am - Class 5",
        "Tuesday: 10am-12pm - Class 6",
        "Wednesday: 8am-10am - Class 7",
        "Thursday: 10am-12pm - Class 8",
        "Friday: 8am-10am - Class 9"
    )
    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Text("$teacherName's Schedule", fontWeight = FontWeight.Bold, fontSize = 22.sp)
        Spacer(modifier = Modifier.height(16.dp))
        schedule.forEach { item ->
            Card(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(vertical = 4.dp)
                    .clickable { onSlotClick(item) },
                shape = RoundedCornerShape(12.dp),
                elevation = CardDefaults.cardElevation(2.dp)
            ) {
                Text(item, modifier = Modifier.padding(12.dp))
            }
        }
        Spacer(modifier = Modifier.height(24.dp))
        OutlinedButton(onClick = onBack) {
            Text("Back")
        }
    }
}

@Composable
fun TeacherScheduleSlotDetailScreen(teacherName: String, slot: String, onBack: () -> Unit) {
    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Text("$teacherName's Slot Detail", fontWeight = FontWeight.Bold, fontSize = 22.sp)
        Spacer(modifier = Modifier.height(16.dp))
        Card(
            modifier = Modifier.fillMaxWidth(),
            shape = RoundedCornerShape(12.dp),
            elevation = CardDefaults.cardElevation(2.dp)
        ) {
            Column(modifier = Modifier.padding(16.dp)) {
                Text("Slot: $slot", fontWeight = FontWeight.Medium)
                Spacer(modifier = Modifier.height(8.dp))
                Text("Details: This is a dummy detail page for the selected schedule slot. You can add more info here, such as class topics, room number, etc.", color = Color.Gray)
            }
        }
        Spacer(modifier = Modifier.height(24.dp))
        OutlinedButton(onClick = onBack) {
            Text("Back")
        }
    }
}

@Composable fun AlphaSchoolStudentsScreen() {
    val students = listOf(
        StudentProfile("John Doe", "Class 5"),
        StudentProfile("Jane Doe", "Class 6"),
        StudentProfile("Alice Smith", "Class 7"),
        StudentProfile("Bob Johnson", "Class 8"),
        StudentProfile("Charlie Brown", "Class 9")
    )
    Column(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Our Students", fontWeight = FontWeight.Bold, fontSize = 22.sp, modifier = Modifier.padding(8.dp))
        LazyColumn(modifier = Modifier.fillMaxWidth()) {
            items(students) { student ->
                ProfileCard(name = student.name, subtitle = student.className)
            }
        }
    }
}

data class TeacherProfile(val name: String, val subject: String)
data class StudentProfile(val name: String, val className: String)

@Composable
fun ProfileCard(name: String, subtitle: String, onClick: (() -> Unit)? = null) {
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .padding(vertical = 6.dp, horizontal = 4.dp)
            .let { if (onClick != null) it.clickable { onClick() } else it },
        shape = RoundedCornerShape(16.dp),
        elevation = CardDefaults.cardElevation(4.dp)
    ) {
        Row(
            modifier = Modifier.padding(16.dp),
            verticalAlignment = Alignment.CenterVertically
        ) {
            Surface(
                modifier = Modifier.size(48.dp).clip(CircleShape),
                color = MaterialTheme.colorScheme.primary
            ) {}
            Spacer(modifier = Modifier.width(16.dp))
            Column {
                Text(name, fontWeight = FontWeight.Bold, fontSize = 18.sp)
                Text(subtitle, color = Color.Gray, fontSize = 14.sp)
            }
        }
    }
}
@Composable fun AlphaSchoolEventsScreen() {
    val context = LocalContext.current
    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Icon(Icons.Default.Lock, contentDescription = "Events", tint = MaterialTheme.colorScheme.primary, modifier = Modifier.size(48.dp))
        Spacer(modifier = Modifier.height(16.dp))
        Card(
            modifier = Modifier.fillMaxWidth(),
            shape = RoundedCornerShape(16.dp),
            elevation = CardDefaults.cardElevation(4.dp)
        ) {
            Column(modifier = Modifier.padding(16.dp)) {
                Text("Upcoming Events", fontWeight = FontWeight.Bold, fontSize = 20.sp)
                Spacer(modifier = Modifier.height(8.dp))
                Text("Annual Day, Sports Day, Science Fair, etc.", color = Color.Gray)
            }
        }
        Spacer(modifier = Modifier.height(24.dp))
        Button(onClick = {
            showDummyNotification(context)
        }) {
            Text("Send Push Notification")
        }
    }
}

fun showDummyNotification(context: Context) {
    val channelId = "alpha_school_channel"
    val notificationId = 1
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
        val name = "Alpha School Channel"
        val descriptionText = "Channel for Alpha School notifications"
        val importance = NotificationManager.IMPORTANCE_DEFAULT
        val channel = NotificationChannel(channelId, name, importance).apply {
            description = descriptionText
        }
        val notificationManager: NotificationManager = context.getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        notificationManager.createNotificationChannel(channel)
    }
    val builder = NotificationCompat.Builder(context, channelId)
        .setSmallIcon(android.R.drawable.ic_dialog_info)
        .setContentTitle("Alpha School Event")
        .setContentText("This is a dummy push notification!")
        .setPriority(NotificationCompat.PRIORITY_DEFAULT)
    with(NotificationManagerCompat.from(context)) {
        if (ActivityCompat.checkSelfPermission(
                context,
                Manifest.permission.POST_NOTIFICATIONS
            ) != PackageManager.PERMISSION_GRANTED
        ) {
            // TODO: Consider calling
            //    ActivityCompat#requestPermissions
            // here to request the missing permissions, and then overriding
            //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
            //                                          int[] grantResults)
            // to handle the case where the user grants the permission. See the documentation
            // for ActivityCompat#requestPermissions for more details.
            return
        }
        notify(notificationId, builder.build())
    }
}
@Composable fun AlphaSchoolGalleryScreen() {
    val dummyImages = List(8) { it }
    Column(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("School Gallery", fontWeight = FontWeight.Bold, fontSize = 22.sp, modifier = Modifier.padding(8.dp))
        Spacer(modifier = Modifier.height(8.dp))
        for (row in 0 until 2) {
            Row(
                modifier = Modifier.fillMaxWidth(),
                horizontalArrangement = Arrangement.SpaceEvenly
            ) {
                for (col in 0 until 4) {
                    val index = row * 4 + col
                    if (index < dummyImages.size) {
                        Surface(
                            modifier = Modifier
                                .size(80.dp)
                                .padding(4.dp),
                            shape = RoundedCornerShape(12.dp),
                            color = MaterialTheme.colorScheme.primary.copy(alpha = 0.2f)
                        ) {
                            Box(contentAlignment = Alignment.Center) {
                                Text("Image ${index + 1}", color = Color.Gray)
                            }
                        }
                    }
                }
            }
        }
    }
}
@Composable fun AlphaSchoolContactScreen() {
    Column(
        modifier = Modifier.fillMaxSize().padding(24.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Icon(Icons.Default.Phone, contentDescription = "Phone", tint = MaterialTheme.colorScheme.primary, modifier = Modifier.size(40.dp))
        Spacer(modifier = Modifier.height(8.dp))
        Text("123 Alpha St, City", fontWeight = FontWeight.Bold, fontSize = 18.sp)
        Spacer(modifier = Modifier.height(4.dp))
        Row(verticalAlignment = Alignment.CenterVertically) {
            Icon(Icons.Default.Phone, contentDescription = "Phone", tint = MaterialTheme.colorScheme.primary, modifier = Modifier.size(20.dp))
            Spacer(modifier = Modifier.width(4.dp))
            Text("1234567890")
        }
        Spacer(modifier = Modifier.height(4.dp))
        Row(verticalAlignment = Alignment.CenterVertically) {
            Icon(Icons.Default.Email, contentDescription = "Email", tint = MaterialTheme.colorScheme.primary, modifier = Modifier.size(20.dp))
            Spacer(modifier = Modifier.width(4.dp))
            Text("info@alphaschool.com")
        }
    }
}

@Composable
fun ScreenPlaceholder(text: String) {
    Box(
        modifier = Modifier.fillMaxSize(),
        contentAlignment = Alignment.Center
    ) {
        Text(text, textAlign = TextAlign.Center, color = Color.Gray)
    }
} 