using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TD_Audio_Tools_1._0._1_BETA
{
    public partial class About : Form
    {
        public About()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            // 指定要打开的 URL
            string url = "https://github.com/KSSW/TD-Audio-Tools";

            // 使用 Process.Start 方法打开默认浏览器并导航到指定的 URL
            try
            {
                Process.Start(new ProcessStartInfo(url) { UseShellExecute = true });
            }
            catch (Exception ex)
            {
                // 处理可能的异常，例如没有默认浏览器或其他问题
                MessageBox.Show($"Unable To Open Website：{ex.Message}");
            }
        }

        private void label4_Click(object sender, EventArgs e)
        {
            // 指定要复制的邮箱地址
            string email = "recipient@example.com";

            // 将邮箱地址复制到剪贴板
            try
            {
                Clipboard.SetText(email);
                // 提示用户邮箱地址已成功复制
                MessageBox.Show("The Email Address Has Been Successfully Copied To The Clipboard", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                // 处理可能的异常，例如复制到剪贴板失败
                MessageBox.Show($"Unable To Copy Email Address：{ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void About_Load(object sender, EventArgs e)
        {

        }
    }
}
