namespace TH_1._0._0
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.textBox_THD = new System.Windows.Forms.TextBox();
            this.button_THD = new System.Windows.Forms.Button();
            this.button_AC3 = new System.Windows.Forms.Button();
            this.textBox_AC3 = new System.Windows.Forms.TextBox();
            this.button_Save = new System.Windows.Forms.Button();
            this.textBox_Save = new System.Windows.Forms.TextBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.button_Execute = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label_Status = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBox_THD
            // 
            this.textBox_THD.Location = new System.Drawing.Point(117, 42);
            this.textBox_THD.Multiline = true;
            this.textBox_THD.Name = "textBox_THD";
            this.textBox_THD.Size = new System.Drawing.Size(506, 23);
            this.textBox_THD.TabIndex = 0;
            this.textBox_THD.TextChanged += new System.EventHandler(this.textBox_THD_TextChanged);
            // 
            // button_THD
            // 
            this.button_THD.Location = new System.Drawing.Point(13, 42);
            this.button_THD.Name = "button_THD";
            this.button_THD.Size = new System.Drawing.Size(98, 23);
            this.button_THD.TabIndex = 1;
            this.button_THD.Text = "Input THD File";
            this.button_THD.UseVisualStyleBackColor = true;
            this.button_THD.Click += new System.EventHandler(this.button1_Click);
            // 
            // button_AC3
            // 
            this.button_AC3.Location = new System.Drawing.Point(13, 71);
            this.button_AC3.Name = "button_AC3";
            this.button_AC3.Size = new System.Drawing.Size(98, 23);
            this.button_AC3.TabIndex = 2;
            this.button_AC3.Text = "Input AC3 File";
            this.button_AC3.UseVisualStyleBackColor = true;
            this.button_AC3.Click += new System.EventHandler(this.button_AC3_Click);
            // 
            // textBox_AC3
            // 
            this.textBox_AC3.Location = new System.Drawing.Point(117, 71);
            this.textBox_AC3.Multiline = true;
            this.textBox_AC3.Name = "textBox_AC3";
            this.textBox_AC3.Size = new System.Drawing.Size(506, 23);
            this.textBox_AC3.TabIndex = 3;
            this.textBox_AC3.TextChanged += new System.EventHandler(this.textBox_AC3_TextChanged);
            // 
            // button_Save
            // 
            this.button_Save.Location = new System.Drawing.Point(13, 151);
            this.button_Save.Name = "button_Save";
            this.button_Save.Size = new System.Drawing.Size(98, 23);
            this.button_Save.TabIndex = 4;
            this.button_Save.Text = "Save File";
            this.button_Save.UseVisualStyleBackColor = true;
            this.button_Save.Click += new System.EventHandler(this.button_Save_Click);
            // 
            // textBox_Save
            // 
            this.textBox_Save.Location = new System.Drawing.Point(117, 151);
            this.textBox_Save.Multiline = true;
            this.textBox_Save.Name = "textBox_Save";
            this.textBox_Save.Size = new System.Drawing.Size(506, 23);
            this.textBox_Save.TabIndex = 5;
            this.textBox_Save.TextChanged += new System.EventHandler(this.textBox_Save_TextChanged);
            // 
            // checkBox1
            // 
            this.checkBox1.Location = new System.Drawing.Point(585, 180);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(38, 21);
            this.checkBox1.TabIndex = 6;
            this.checkBox1.Text = "-t";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // label1
            // 
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(115, 103);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(508, 45);
            this.label1.TabIndex = 7;
            this.label1.Text = "NOTICE:\r\nAC3 File Can Be a Silent And Mono Stream;\r\nThe AC3 Bitrate Must Be Equal" +
    " To Or Greater Than 64 Kbps.";
            // 
            // label2
            // 
            this.label2.ForeColor = System.Drawing.Color.Red;
            this.label2.Location = new System.Drawing.Point(115, 182);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(448, 23);
            this.label2.TabIndex = 8;
            this.label2.Text = "-t: Truncate Longer Stream To Length Of Shorter Stream";
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // button_Execute
            // 
            this.button_Execute.BackColor = System.Drawing.Color.DeepSkyBlue;
            this.button_Execute.Location = new System.Drawing.Point(13, 208);
            this.button_Execute.Name = "button_Execute";
            this.button_Execute.Size = new System.Drawing.Size(610, 30);
            this.button_Execute.TabIndex = 9;
            this.button_Execute.Text = "Execute";
            this.button_Execute.UseVisualStyleBackColor = false;
            this.button_Execute.Click += new System.EventHandler(this.button_Execute_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(637, 25);
            this.menuStrip1.TabIndex = 12;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(55, 21);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(13, 244);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(610, 30);
            this.progressBar1.TabIndex = 13;
            this.progressBar1.Click += new System.EventHandler(this.progressBar1_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label_Status);
            this.groupBox1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.groupBox1.ForeColor = System.Drawing.Color.Blue;
            this.groupBox1.Location = new System.Drawing.Point(13, 280);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(610, 64);
            this.groupBox1.TabIndex = 14;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Status Bar";
            // 
            // label_Status
            // 
            this.label_Status.Font = new System.Drawing.Font("Arial", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_Status.ForeColor = System.Drawing.Color.Red;
            this.label_Status.Location = new System.Drawing.Point(192, 11);
            this.label_Status.Name = "label_Status";
            this.label_Status.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label_Status.Size = new System.Drawing.Size(258, 50);
            this.label_Status.TabIndex = 11;
            this.label_Status.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label_Status.Click += new System.EventHandler(this.label_Status_Click);
            // 
            // Form1
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.Silver;
            this.ClientSize = new System.Drawing.Size(637, 356);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.button_Execute);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.textBox_Save);
            this.Controls.Add(this.button_Save);
            this.Controls.Add(this.textBox_AC3);
            this.Controls.Add(this.button_AC3);
            this.Controls.Add(this.button_THD);
            this.Controls.Add(this.textBox_THD);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TD Audio Tools 1.0.3 BETA";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox_THD;
        private System.Windows.Forms.Button button_THD;
        private System.Windows.Forms.Button button_AC3;
        private System.Windows.Forms.TextBox textBox_AC3;
        private System.Windows.Forms.Button button_Save;
        private System.Windows.Forms.TextBox textBox_Save;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button button_Execute;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label_Status;
    }
}

